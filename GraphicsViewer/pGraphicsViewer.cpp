#include "pGraphicsViewer.h"
#include <QWheelEvent>
#include <QScrollBar>
pGraphicsViewer::pGraphicsViewer(QWidget * parent)
	: QGraphicsView(parent), impl(new pGraphicsViewerImpl{this})
{
	setScene(impl->scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
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

void pGraphicsViewer::mouseDoubleClickEvent(QMouseEvent * _event)
{
	FitImage();
}

void pGraphicsViewer::mousePressEvent(QMouseEvent * event)
{
	impl->ptPressed = mapToScene(event->pos());
	impl->isPressed = true;
}

void pGraphicsViewer::mouseMoveEvent(QMouseEvent * event)
{
	if (impl->isPressed)
	{
		QPointF gap = matrix().m11() * (mapToScene(event->pos()) - impl->ptPressed);
		verticalScrollBar()->setValue(-gap.y() + verticalScrollBar()->value());
		horizontalScrollBar()->setValue(-gap.x() + horizontalScrollBar()->value());
	}

}

void pGraphicsViewer::mouseReleaseEvent(QMouseEvent * event)
{
	impl->isPressed = false;
}

void pGraphicsViewer::wheelEvent(QWheelEvent * _event)
{
	if ((_event->delta() > 0) && (this->matrix().m11() >= 10))
	{
		return;
	}
	else if ((_event->delta() < 0) && (this->matrix().m11() <= 0.1))
	{
		return;
	}
	else
	{
		int wheelDeltaValue = _event->delta();
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


