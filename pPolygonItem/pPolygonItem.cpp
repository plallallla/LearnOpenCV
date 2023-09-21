#include "pPolygonItem.h"
#include <QPainter>
extern "C" Q_DECL_EXPORT  pAbstractItem * ItemCreator()
{
	return new pPolygonItem;
}

pPolygonItem::pPolygonItem() : impl(new pPolygonItemImpl{this})
{
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsSelectable);
	setFlag(QGraphicsItem::ItemIsMovable);
}

void pPolygonItem::SetPolygon(const QPolygonF & data)
{
	impl->polygon = data;
}

void pPolygonItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (impl->polygon.isEmpty())
	{
		return;
	}
	Q_UNUSED(widget);
	if (option->state & QStyle::State_Selected)
	{
		painter->setPen(impl->penSelected);
		painter->setBrush(impl->brushSelected);
		painter->drawPolygon(impl->polygon);
		painter->setPen(QPen(Qt::black));
		painter->setBrush(QBrush(Qt::white));
		painter->translate(impl->polygon[0]);
		painter->drawEllipse(-5, -5, 10, 10);
		for (size_t i = 0; i < impl->polygon.size()-1; i++)
		{
			painter->translate(impl->polygon[i + 1] - impl->polygon[i]);
			painter->drawEllipse(-5, -5, 10, 10);
		}

	}
	else
	{
		painter->setPen(impl->penNotSelected);
		painter->setBrush(impl->brushNotSelected);
		painter->drawPolygon(impl->polygon);
	}
}

QPainterPath pPolygonItem::shape() const
{
	QPainterPath ans;
	int size = impl->polygon.size() - 1;
	for (size_t i = 0; i < size; i++)
	{
		ans += impl->LineToRectPath(impl->polygon[i], impl->polygon[i + 1]);
	}
	ans += impl->LineToRectPath(impl->polygon[size], impl->polygon[0]);
	return ans;
}

MouseInterAct pPolygonItem::GetInterAct(int type)
{
	switch (type)
	{
	case 0:
		return impl->double_click;
	case 1:
		return impl->press;
	case 2:
		return impl->move;
	case 3:
		return impl->release;
	default:
		break;
	}
	return nullptr;
}

QRectF pPolygonItem::boundingRect() const
{
	auto r = impl->polygon.boundingRect();
	r.adjust(-10, -10, 10, 10);
	return r;
}

void pPolygonItem::SetPen(const QPen & pen, bool isSelected)
{
	if (isSelected)
	{
		impl->penSelected = pen;
	}
	else
	{
		impl->penNotSelected = pen;
	}
}

void pPolygonItem::SetBrush(const QBrush & brush, bool isSelected)
{
	if (isSelected)
	{
		impl->brushSelected = brush;
	}
	else
	{
		impl->brushNotSelected = brush;
	}
}

#include <qDebug>
void pPolygonItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
	QGraphicsItem::hoverMoveEvent(event);
	//TODO
	//每次移动遍历全部点，有待优化
	QPointF pos = event->scenePos();
	for (size_t i = 0; i < impl->polygon.size(); i++)
	{
		if (abs(pos.x() - impl->polygon[i].x()) < 10 && abs(pos.y() - impl->polygon[i].y()) < 10)
		{
			impl->curPoint = i;
			impl->mode = pPolygonItemImpl::Mode::Change;
			return;
		}
	}
	impl->mode = pPolygonItemImpl::Mode::Move;
}
void pPolygonItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsItem::mousePressEvent(event);
	switch (impl->mode)
	{
	case pPolygonItemImpl::Mode::Default:
		return;
	case pPolygonItemImpl::Mode::Move:
	case pPolygonItemImpl::Mode::Change:
		impl->ptPressed = event->pos();
		impl->bPressed = true;
		return;
	}
}

void pPolygonItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	QPointF gap = (event->pos() - impl->ptPressed);
	switch (impl->mode)
	{
	case pPolygonItemImpl::Mode::Default:
		break;
	case pPolygonItemImpl::Mode::Move:
		for (size_t i = 0; i < impl->polygon.size(); i++)
		{
			impl->polygon[i] += gap;
		}
		break;
	case pPolygonItemImpl::Mode::Change:
		impl->polygon[impl->curPoint] += gap;
		break;
	}
	impl->ptPressed = event->pos();
	QGraphicsItem::mouseMoveEvent(event);
}

void pPolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsItem::mouseReleaseEvent(event);
	impl->bPressed = false;
	switch (impl->mode)
	{
	case pPolygonItemImpl::Mode::Default:
		return;
	case pPolygonItemImpl::Mode::Move:
		return;
	case pPolygonItemImpl::Mode::Change:
		return;
	}
}
