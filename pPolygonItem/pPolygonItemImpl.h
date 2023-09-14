#pragma once
#include "pPolygonItem.h"
#include "../GraphicsViewer/ViewerDef.h"
#include "../GraphicsViewer/pAbstractItemImpl.h"

class pPolygonItem;
class pPolygonItemImpl : public pAbstractItemImpl
{
public:
	pPolygonItemImpl(pPolygonItem * _impl);
private:
	friend class pPolygonItem;
	QPainterPath ShapeLine(const QPointF &pt1, const QPointF &pt2) const;
	QScopedPointer<pPolygonItem> impl;
	QPolygonF polygon;
};

