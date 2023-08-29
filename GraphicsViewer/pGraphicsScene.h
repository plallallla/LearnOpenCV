#pragma once
#include <QGraphicsScene>
#include <QPainter>
class pGraphicsScene :
	public QGraphicsScene
{
public:
	pGraphicsScene(QObject *parent = nullptr);
	~pGraphicsScene();
	QRectF GetShowRect() const;
	void SetBackground(const QImage *);
	void SetBackground(const QPixmap *);
	void removeBackGround();
protected:
	void drawBackground(QPainter *painter, const QRectF &rect) override;
private:
	void ResetRect();
private:
	bool isImage{ true };
	QImage iBackground;
	QPixmap pBackground;
};

