#include "ImgGrayOut.h"

ImgGrayOut::ImgGrayOut(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	ui.graphicsView->OpenImage(QImage("test.bmp"));

}

ImgGrayOut::~ImgGrayOut()
{}
