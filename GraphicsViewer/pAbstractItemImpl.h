#pragma once
#include "ViewerDef.h"
#include <QPen>
#include <QBrush>
class pAbstractItemImpl
{
protected:
	QPen pen{ Qt::red,3 };
	QBrush brush{ Qt::transparent };
	static MouseInterAct double_click;
	static MouseInterAct press;
	static MouseInterAct move;
	static MouseInterAct release;
};

