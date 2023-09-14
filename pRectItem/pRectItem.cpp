#include "pRectItem.h"

pRectItem::pRectItem()
{
}

QRectF pRectItem::boundingRect() const
{
	return QRectF();
}

MouseInterAct pRectItem::GetInterAct(int type)
{
	return MouseInterAct();
}

void pRectItem::SetPen(const QPen & pen)
{
}

void pRectItem::SetBrush(const QBrush & brush)
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
