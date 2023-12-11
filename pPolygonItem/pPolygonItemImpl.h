#pragma once
#include "pPolygonItem.h"
#include "../GraphicsViewer/ViewerDef.h"
#include "../GraphicsViewer/pAbstractItemImpl.h"
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QScopedPointer>
#include <QGraphicsSceneMouseEvent>

class pPolygonItem;
class pPolygonItemImpl : public pAbstractItemImpl
{
public:
	pPolygonItemImpl(pPolygonItem * _impl);
private:
	friend class pPolygonItem;
	enum class Mode { Default, Move, Change, } mode = Mode::Default;
	QPainterPath LineToRectPath(const QPointF &pt1, const QPointF &pt2) const;
	QScopedPointer<pPolygonItem> impl;
	QPolygonF polygon;
	bool bPressed{ false };
	QPointF ptPressed;
	int curPoint{ -1 };
};

