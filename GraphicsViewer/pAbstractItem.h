#pragma once
#include "ViewerDef.h"
#include <QGraphicsItem>
#include <QScopedPointer>

class pAbstractItem : public QGraphicsItem
{
public:
	pAbstractItem() = default;
	virtual MouseInterAct GetInterAct(int type) = 0;
	virtual void SetPen(const QPen& pen, bool isSelected) = 0;
	virtual void SetBrush(const QBrush& brush, bool isSelected) = 0;
};
