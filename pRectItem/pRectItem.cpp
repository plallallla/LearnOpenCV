#include "pRectItem.h"

extern "C" Q_DECL_EXPORT  pAbstractItem * ItemCreator()
{
	return new pRectItem;
}

pRectItem::pRectItem() : impl{ new pRectItemImpl{this} }
{
}

QRectF pRectItem::boundingRect() const
{
	return QRectF();
}

MouseInterAct pRectItem::GetInterAct(int type)
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

void pRectItem::SetPen(const QPen & pen, bool isSelected)
{
}

void pRectItem::SetBrush(const QBrush & brush, bool isSelected)
{
}

void pRectItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
}

void pRectItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
}


void pRectItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
}

void pRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
}

void pRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
}
