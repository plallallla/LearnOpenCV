#pragma once
#include "ViewerDef.h"
#include <QGraphicsItem>
#include <QScopedPointer>

class pAbstractItem : public QGraphicsItem
{
public:
	pAbstractItem() = default;
	virtual MouseInterAct GetInterAct(int type) = 0;
	virtual void SetPen(const QPen& pen) = 0;
	virtual void SetBrush(const QBrush& brush) = 0;
};
