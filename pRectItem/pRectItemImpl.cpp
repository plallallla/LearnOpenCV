#include "pRectItemImpl.h"
#include "../GraphicsViewer/ViewerDef.h"
#include "../GraphicsViewer/pAbstractItemImpl.h"
#include "../GraphicsViewer//pGraphicsViewerImpl.h"
#include <QMouseEvent>

pRectItemImpl::pRectItemImpl(pRectItem * p) : impl{ p }
{
}

#include <qDebug>
MouseInterAct pRectItemImpl::double_click = nullptr;

MouseInterAct pRectItemImpl::press = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	qDebug() << __func__ << "press" << press << view->impl->objectName();
	view->isPressed = true;
	view->ptPressed = view->impl->mapToScene(event->pos());
	view->vecTemps.append(view->scene->addRect(QRectF(view->ptPressed, view->ptPressed), QPen(Qt::red, 2)));
};

MouseInterAct pRectItemImpl::move = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	qDebug() << __func__ << "move" << move << view->impl->objectName();
	if (view->isPressed)
	{
		static_cast<QGraphicsRectItem*>(view->vecTemps.last())->setRect(QRectF(view->ptPressed, view->impl->mapToScene(event->pos())));
	}
};

MouseInterAct pRectItemImpl::release = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	qDebug() << __func__ << "release" << release << view->impl->objectName();
	view->isPressed = false;
	view->scene->removeItem(view->vecTemps[0]);
};