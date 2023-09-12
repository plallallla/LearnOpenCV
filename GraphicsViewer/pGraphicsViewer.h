#pragma once
#include "graphicsviewer_global.h"
#include "pGraphicsViewerImpl.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QScopedPointer>

class pGraphicsScene;
class GRAPHICSVIEWER_EXPORT pGraphicsViewer : public QGraphicsView
{
public:
    pGraphicsViewer(QWidget* parent = nullptr);
	~pGraphicsViewer() = default;
	//action
	void OpenImage(const QPixmap& _img);
	void OpenImage(const QImage& _img);
	void FitImage();
	void DrawRect(const QRectF& rect ,const QPen p = QPen(Qt::red));
	void DrawPolygon(const QVector<QPointF>& polygon, const QPen p = QPen(Qt::red));
	QGraphicsLineItem * DrawLine(const QLineF& line, const QPen p = QPen(Qt::red));
	void ClearItems();

	void testPolygon();

protected:
	void mouseDoubleClickEvent(QMouseEvent *_event) override;
	void mousePressEvent(QMouseEvent *_event) override;
	void mouseMoveEvent(QMouseEvent *_event) override;
	void mouseReleaseEvent(QMouseEvent *_event) override;
	void wheelEvent(QWheelEvent *_event) override;
private:
	friend class pGraphicsViewerImpl;
	QScopedPointer<pGraphicsViewerImpl> impl;
};

