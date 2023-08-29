#pragma once
#include "graphicsviewer_global.h"
#include "pGraphicsScene.h"
#include "pGraphicsViewerImpl.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>


class pGraphicsScene;
class pGraphicsViewerImpl;
class GRAPHICSVIEWER_EXPORT pGraphicsViewer : public QGraphicsView
{
public:
    pGraphicsViewer(QWidget* parent = nullptr);
//action
	void OpenImage(const QPixmap& _img);
	void OpenImage(const QImage& _img);
	void FitImage();
protected:
	void mouseDoubleClickEvent(QMouseEvent *_event) override;
	void mousePressEvent(QMouseEvent *_event) override;
	void mouseMoveEvent(QMouseEvent *_event) override;
	void mouseReleaseEvent(QMouseEvent *_event) override;
	void wheelEvent(QWheelEvent *_event) override;
private:
	friend class pGraphicsViewerImpl;
	pGraphicsViewerImpl* impl;
};

