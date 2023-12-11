#pragma once

#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_ImgGrayOut.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class ImgGrayOut : public QWidget
{
    Q_OBJECT

public:
    ImgGrayOut(QWidget *parent = nullptr);
    ~ImgGrayOut();

private:
    Ui::ImgGrayOutClass ui;
};
