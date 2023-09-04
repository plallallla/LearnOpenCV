#pragma once

#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_BugDetect.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class BugDetect : public QWidget
{
    Q_OBJECT

public:
    BugDetect(QWidget *parent = nullptr);
    ~BugDetect();
private:
	void show8Gray(const cv::Mat &img);
private:
    Ui::BugDetectClass ui;
};
