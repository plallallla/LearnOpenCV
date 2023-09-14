#include "pPolygonItemImpl.h"
#include <QMouseEvent>
#include "../GraphicsViewer//pGraphicsViewerImpl.h"

pPolygonItemImpl::pPolygonItemImpl(pPolygonItem * _impl)
	: impl(_impl)
{
}

QPainterPath pPolygonItemImpl::ShapeLine(const QPointF & pt1, const QPointF & pt2) const
{
	QPainterPath ans;
	QLineF line = QLineF(pt1, pt2);
	QPointF center = (pt1 + pt2) / 2;
	qreal angle = line.angleTo(QLineF(QPointF(0, 0), QPointF(1, 0)));
	qreal length = line.length();
	QRect rect(-(length + 10) / 2, -10 / 2, length + 10, 10);
	QTransform t;
	t.translate(center.x(), center.y());
	t.rotate(angle);
	ans.addPolygon(t.mapToPolygon(rect));
	ans.closeSubpath();
	return ans;
}

#include <qDebug>

MouseInterAct pPolygonItemImpl::double_click = [](QMouseEvent *event, pGraphicsViewerImpl *view)->void
{
	view->isPressed = false;
	view->impl->setMouseTracking(false);

	for (int i = 0;i < view->vecLines.size(); i++)
	{
		view->scene->removeItem(view->vecLines[i]);
	}
	view->scene->addPolygon(view->vecPoints,QPen(Qt::green));
	view->vecLines.clear();
	static_cast<pPolygonItem*>(view->curItem)->SetPolygon(view->vecPoints);
	view->vecPoints.clear();
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
	qDebug() << view->scene->items();
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
