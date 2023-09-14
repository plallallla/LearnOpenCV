#pragma once

#include "prectitem_global.h"
#include "../GraphicsViewer/pAbstractItem.h"
#include "pRectItemImpl.h"
#include <QGraphicsItem>
#include <QScopedPointer>

class pRectItemImpl;
class pRectItem : public pAbstractItem
{
public:
	pRectItem();

	QRectF boundingRect() const override;
	MouseInterAct GetInterAct(int type) override;
	void SetPen(const QPen& pen) override;
	void SetBrush(const QBrush& brush) override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;


protected:
	//事件响应函数,移动、形变均基于以下函数的联动
	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	QScopedPointer<pRectItemImpl> impl;
};
