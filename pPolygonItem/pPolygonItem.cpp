#include "pPolygonItem.h"
#include <QPainter>
extern "C" Q_DECL_EXPORT  pAbstractItem * ItemCreator()
{
	return new pPolygonItem;
}

pPolygonItem::pPolygonItem() : impl(new pPolygonItemImpl{this})
{
}

void pPolygonItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	Q_UNUSED(widget);
	painter->setPen(impl->pen);
	painter->setBrush(impl->brush);
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
	return QRectF();
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
