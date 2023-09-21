#pragma once
#include "ViewerDef.h"
#include <QPen>
#include <QBrush>
class pAbstractItemImpl
{
	Q_DISABLE_COPY(pAbstractItemImpl);
public:
	pAbstractItemImpl() = default;
protected:
	QPen penSelected{ Qt::green,3 };
	QPen penNotSelected{ Qt::red,3 };
	QBrush brushSelected{ Qt::transparent };
	QBrush brushNotSelected{ Qt::transparent };
	static MouseInterAct double_click;
	static MouseInterAct press;
	static MouseInterAct move;
	static MouseInterAct release;
};

