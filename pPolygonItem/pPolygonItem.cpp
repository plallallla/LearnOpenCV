#include "pPolygonItem.h"
#include <QPainter>
extern "C" Q_DECL_EXPORT  pAbstractItem * ItemCreator()
{
	return new pPolygonItem;
}

pPolygonItem::pPolygonItem() : impl(new pPolygonItemImpl{this})
{
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
	painter->setPen(impl->pen);
	painter->setBrush(impl->brush);
	painter->drawPolygon(impl->polygon);

	painter->setPen(QPen(Qt::blue, 2, Qt::DotLine));

	painter->drawPath(shape());

	painter->setPen(QPen(Qt::green, 2, Qt::DotLine));
	painter->drawRect(boundingRect());
}

QPainterPath pPolygonItem::shape() const
{
	QPainterPath ans;
	int size = impl->polygon.size() - 1;
	for (size_t i = 0; i < size; i++)
	{
		ans += impl->ShapeLine(impl->polygon[i], impl->polygon[i + 1]);
	}
	ans += impl->ShapeLine(impl->polygon[size], impl->polygon[0]);
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
	return MouseInterAct();
}

QRectF pPolygonItem::boundingRect() const
{
	auto r = impl->polygon.boundingRect();
	r.adjust(-10, -10, 10, 10);
	return r;
}

void pPolygonItem::SetPen(const QPen & pen)
{
	impl->pen = pen;
}

void pPolygonItem::SetBrush(const QBrush & brush)
{
	impl->brush = brush;
}

void pPolygonItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
}

void pPolygonItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
}

void pPolygonItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
}

void pPolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
}
