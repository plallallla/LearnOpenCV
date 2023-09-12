#include "pPolygonItemImpl.h"
#include <QMouseEvent>
#include "../GraphicsViewer//pGraphicsViewerImpl.h"

pPolygonItemImpl::pPolygonItemImpl(pPolygonItem * _impl)
	: impl(_impl)
{
}

#include <qDebug>

MouseInterAct pPolygonItemImpl::double_click = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	view->scene->addLine(QLineF(view->vecPoints[0], view->impl->mapToScene(event->pos())), QPen(Qt::red, 2));
	view->curItem = nullptr;
	view->vecPoints.clear();
	view->vecLines.clear();
	view->isPressed = false;
	view->impl->setMouseTracking(false);
	view->scene->addItem(view->curItem);
	view->curItem = nullptr;
	qDebug() << view->scene->items();
};

MouseInterAct pPolygonItemImpl::press = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	qDebug() << __func__ << "press" << press << view->impl->objectName();
	view->ptPressed = view->impl->mapToScene(event->pos());
	view->vecPoints << view->ptPressed;
	if (view->vecLines.isEmpty())
	{
		view->vecLines << view->scene->addLine(QLineF(view->vecPoints[0], view->ptPressed), QPen(Qt::red, 2));
	}
	view->vecLines << view->scene->addLine(QLineF(view->ptPressed, view->ptPressed), QPen(Qt::red, 2));
	view->isPressed = true;
};

MouseInterAct pPolygonItemImpl::move = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void 
{
	qDebug() << __func__ << "move" << move << view->impl->objectName();
	if (view->isPressed)
	{
		view->vecLines.first()->setLine(QLineF(view->vecPoints[0], view->impl->mapToScene(event->pos())));
		view->vecLines.last()->setLine(QLineF(view->ptPressed, view->impl->mapToScene(event->pos())));
	}
};

MouseInterAct pPolygonItemImpl::release = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	qDebug() << __func__ << "release" << release << view->impl->objectName();
	//view->scene->addLine(QLineF(view->ptPressed, view->impl->mapToScene(event->pos())), QPen(Qt::red, 2));
	/*view->scene->removeItem(view->dLine);*/

};
