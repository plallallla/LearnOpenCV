#pragma once
#include "../GraphicsViewer/ViewerDef.h"
#include "../GraphicsViewer/pAbstractItemImpl.h"
class pRectItem;
class QGraphicsRectItem;
class pRectItemImpl : public pAbstractItemImpl
{
public:
	pRectItemImpl(pRectItem *p);
private:
	friend class pRectItem;
	pRectItem *impl;
	QRectF rect;
	static QGraphicsRectItem *paintTemp;
};
