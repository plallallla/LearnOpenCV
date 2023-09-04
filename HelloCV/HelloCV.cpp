#include "HelloCV.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include "../../include/GBmp.hpp"

void setAllPixel(cv::Mat &img)
{
	int length = img.cols * img.rows * img.channels();
	auto p = img.ptr<uchar>(0);
	for (size_t i = 0; i < length; i++)
	{
		(*p++) = 150;
	}
}

QImage ConvertFromMat(const cv::Mat & mat)
{
	return QImage(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_Indexed8);
}

HelloCV::HelloCV(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
}

HelloCV::~HelloCV()
{}
