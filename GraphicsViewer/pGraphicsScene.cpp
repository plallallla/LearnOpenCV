#include "pGraphicsScene.h"

pGraphicsScene::pGraphicsScene(QObject * parent)
{
}

pGraphicsScene::~pGraphicsScene()
{
}

QRectF pGraphicsScene::GetShowRect() const
{
	return isImage ? iBackground.rect() : pBackground.rect();
}

void pGraphicsScene::SetBackground(const QImage *img)
{
	isImage = true;
	iBackground = img->copy();
	ResetRect();
}

void pGraphicsScene::SetBackground(const QPixmap *img)
{
	isImage = false;
	pBackground = img->copy();
	ResetRect();
}

void pGraphicsScene::removeBackGround()
{
	if (isImage)
	{
		iBackground.load("");
	}
	else
	{
		pBackground.load("");
	}
	setSceneRect(QRectF());
	update();
}

void pGraphicsScene::drawBackground(QPainter * painter, const QRectF & rect)
{
	if (views().count() == 0)
	{
		return;
	}
	if (isImage)
	{
		painter->drawImage(iBackground.rect(), iBackground, QRect());
	}
	else
	{
		painter->drawPixmap(pBackground.rect(), pBackground, QRect());
	}
}

void pGraphicsScene::ResetRect()
{
	QRectF b = isImage ? iBackground.rect() : pBackground.rect();
	QRectF a = QRectF(b.x() - b.width(), b.y() - b.height(), 3 * b.width(), 3 * b.height());
	setSceneRect(a);
	update();
}
