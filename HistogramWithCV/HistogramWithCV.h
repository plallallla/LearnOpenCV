#pragma once

#include <QtWidgets/QWidget>
#include <opencv2/opencv.hpp>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_HistogramWithCV.h"

#pragma comment(lib,"GraphicsViewer.lib")
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif

class HistogramWithCV : public QWidget
{
    Q_OBJECT

public:
    HistogramWithCV(QWidget *parent = nullptr);
    ~HistogramWithCV();

private:
    Ui::HistogramWithCVClass ui;
};
