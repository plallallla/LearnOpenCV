#pragma once

#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_morphologyExWithCV.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class morphologyExWithCV : public QWidget
{
    Q_OBJECT

public:
    morphologyExWithCV(QWidget *parent = nullptr);
    ~morphologyExWithCV();
	void ShowRGB(const cv::Mat &img);
	void ShowGray(const cv::Mat &img);

	enum class Mode
	{
		MODE_ORI,
		MODE_DILATE,
		MODE_ERODE,
	} mode = Mode::MODE_ORI;

private:
    Ui::morphologyExWithCVClass ui;
};
