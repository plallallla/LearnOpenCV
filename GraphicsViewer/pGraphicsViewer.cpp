#include "pGraphicsViewer.h"
#include <QWheelEvent>
#include <QScrollBar>
#include <QSurfaceFormat>
#include <QOpenGLWidget>
#include <QGLFormat>
#include <QMessageBox>

pGraphicsViewer::pGraphicsViewer(QWidget * parent)
	: QGraphicsView(parent), impl(new pGraphicsViewerImpl{this})
{
	setScene(impl->scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
	if (!impl->InitItemFunc())
	{
		QMessageBox::critical(this, "Module error", "wrong!");
	}
}


void pGraphicsViewer::OpenImage(const QPixmap & _img)
{
	impl->scene->SetBackground(&_img);
}

void pGraphicsViewer::OpenImage(const QImage & _img)
{
	impl->scene->SetBackground(&_img);
}

void pGraphicsViewer::FitImage()
{
	fitInView(impl->scene->GetShowRect(), Qt::KeepAspectRatio);
}

void pGraphicsViewer::DrawRect(const QRectF & rect, const QPen p)
{
	impl->scene->addRect(rect, p);
}

void pGraphicsViewer::DrawPolygon(const QVector<QPointF>& polygon, const QPen p)
{
	impl->scene->addPolygon(polygon, p);
}

QGraphicsLineItem * pGraphicsViewer::DrawLine(const QLineF & line, const QPen p)
{
	return impl->scene->addLine(line, p);
}

void pGraphicsViewer::ClearItems()
{
	for (auto i : impl->scene->items())
	{
		impl->scene->removeItem(i);
	}
}

void pGraphicsViewer::testPolygon()
{
	impl->curItem = impl->mapItemFunc["polygon"]();
	setMouseTracking(true);
}

void pGraphicsViewer::testRect()
{
	impl->curItem = impl->mapItemFunc["rectangle"]();
	auto i = impl->curItem;
	setMouseTracking(true);
}

void pGraphicsViewer::mouseDoubleClickEvent(QMouseEvent * event)
{
	if (impl->curItem)
	{
		impl->curItem->GetInterAct(0)(event, impl.get());
	}
	else if(scene()->selectedItems().isEmpty())
	{
		FitImage();
	}
	QGraphicsView::mouseDoubleClickEvent(event);
}

void pGraphicsViewer::mousePressEvent(QMouseEvent * event)
{
	if (impl->curItem)
	{
		impl->curItem->GetInterAct(1)(event, impl.get());
	}
	else if (scene()->selectedItems().isEmpty())
	{
		impl->ptPressed = mapToScene(event->pos());
		impl->isPressed = true;
	}
	QGraphicsView::mousePressEvent(event);
}

void pGraphicsViewer::mouseMoveEvent(QMouseEvent * event)
{
	if (impl->curItem)
	{
		impl->curItem->GetInterAct(2)(event, impl.get());
	}
	else if (impl->isPressed && scene()->selectedItems().isEmpty())
	{
		QPointF gap = matrix().m11() * (mapToScene(event->pos()) - impl->ptPressed);
		verticalScrollBar()->setValue(-gap.y() + verticalScrollBar()->value());
		horizontalScrollBar()->setValue(-gap.x() + horizontalScrollBar()->value());
	}
	QGraphicsView::mouseMoveEvent(event);
}

void pGraphicsViewer::mouseReleaseEvent(QMouseEvent * event)
{
	if (impl->curItem)
	{
		impl->curItem->GetInterAct(3)(event, impl.get());
	}
	else if (impl->isPressed && scene()->selectedItems().isEmpty())
	{
		impl->isPressed = false;
	}
	QGraphicsView::mouseReleaseEvent(event);
}

void pGraphicsViewer::wheelEvent(QWheelEvent * event)
{
	if ((event->delta() > 0) && (this->matrix().m11() >= 10))
	{
		return;
	}
	else if ((event->delta() < 0) && (this->matrix().m11() <= 0.1))
	{
		return;
	}
	else
	{
		int wheelDeltaValue = event->delta();
		if (wheelDeltaValue > 0)
		{
			scale(1.2, 1.2);
		}
		else
		{
			scale(1.0 / 1.2, 1.0 / 1.2);
		}
	}
}


