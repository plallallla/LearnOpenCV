#pragma once

#include "../GraphicsViewer/pAbstractItem.h"
#include "pPolygonItemImpl.h"


class pPolygonItemImpl;
class pPolygonItem : public pAbstractItem
{
public:
    pPolygonItem();

	QRectF boundingRect() const override;
	MouseInterAct GetInterAct(int type) override;
	void SetPen(const QPen& pen, bool isSelected = false) override;
	void SetBrush(const QBrush& brush, bool isSelected = false) override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
	QPainterPath shape() const override;
	void SetPolygon(const QPolygonF& data);

protected:
	//事件响应函数,移动、形变均基于以下函数的联动
	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	QScopedPointer<pPolygonItemImpl> impl;
};

