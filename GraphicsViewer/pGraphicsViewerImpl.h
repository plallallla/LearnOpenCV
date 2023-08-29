#pragma once
#include "pGraphicsViewer.h"
#include "pGraphicsScene.h"

using funcGetItem = QGraphicsItem * (*)(void);

class pGraphicsViewer;
class pGraphicsViewerImpl
{
public:
	pGraphicsViewerImpl(pGraphicsViewer *_impl);
	pGraphicsViewer* impl;
	pGraphicsScene* scene;
	QPointF ptPressed;
	bool isPressed = false;
	QVector<funcGetItem> vecItemFunc;
};