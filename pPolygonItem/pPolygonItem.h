#pragma once

#include "ppolygonitem_global.h"
#include "../GraphicsViewer/pAbstractItem.h"
#include "pPolygonItemImpl.h"
#include <QGraphicsItem>
#include <QScopedPointer>

class pPolygonItemImpl;
class pPolygonItem : public pAbstractItem
{
public:
    pPolygonItem();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
	MouseInterAct GetInterAct(int type) override;
	QRectF boundingRect() const override;
	void SetPen(const QPen& pen) override;
	void SetBrush(const QBrush& brush) override;
	int Test() override { return 1; };
protected:
	//事件响应函数,移动、形变均基于以下函数的联动
	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	QScopedPointer<pPolygonItemImpl> impl;
};

