#pragma once

#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_FilteringWithCV.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class FilteringWithCV : public QWidget
{
    Q_OBJECT

public:
    FilteringWithCV(QWidget *parent = nullptr);
    ~FilteringWithCV();

	enum class showedImg
	{
		None,
		EdgeDetection_blur,
		EdgeDetection_GaussianBlur,
		EdgeDetection_medianBlur,
	} showed = showedImg::None;

private:
	void ShowImg(cv::Mat &cvImage);
    Ui::FilteringWithCVClass ui;
};
