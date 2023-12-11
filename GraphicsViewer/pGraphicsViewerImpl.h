#pragma once
#include "ViewerDef.h"
#include "pGraphicsViewer.h"
#include "pGraphicsScene.h"
#include "pAbstractItem.h"

class pAbstractItem;
class pGraphicsViewer;
class pGraphicsViewerImpl
{
public:
	pGraphicsViewerImpl(pGraphicsViewer *_impl);
private:
	bool InitItemFunc();
private:
	friend class pGraphicsViewer;
	pGraphicsViewer* impl;
	pGraphicsScene* scene;
	QPointF ptPressed;
	bool isPressed = false;
	pAbstractItem *curItem = nullptr;
	QMap<QString, fGetItem> mapItemFunc;
	QVector<QPointF> vecPoints;
	QVector<QGraphicsItem*> vecTempItems;
};