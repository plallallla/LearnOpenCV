#pragma once

#include <QtWidgets/QWidget>
#include "../GraphicsViewer/pGraphicsViewer.h"
#include "ui_ImgCvtWithCV.h"

#include <opencv3/opencv2/opencv.hpp>

#pragma comment(lib,"GraphicsViewer.lib")


class ImgCvtWithCV : public QWidget
{
    Q_OBJECT

public:
    ImgCvtWithCV(QWidget *parent = nullptr);
    ~ImgCvtWithCV();

private:
    Ui::ImgCvtWithCVClass ui;
};
