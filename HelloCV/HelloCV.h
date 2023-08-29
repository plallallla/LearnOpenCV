#pragma once
#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "ui_HelloCV.h"
#include "../GraphicsViewer/pGraphicsViewer.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class HelloCV : public QWidget
{
    Q_OBJECT

public:
    HelloCV(QWidget *parent = nullptr);
    ~HelloCV();

private:
    Ui::HelloCVClass ui;
};
