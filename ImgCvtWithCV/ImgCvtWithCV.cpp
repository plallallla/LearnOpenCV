#include "ImgCvtWithCV.h"

ImgCvtWithCV::ImgCvtWithCV(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	connect(ui.pushButton_2, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		qImage.save("../LenaGRAY.bmp");
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//Canny边缘检测
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::blur(cvImage, cvImage, cv::Size(3, 3));//3*3内核降噪
		cv::Canny(cvImage, cvImage, 3, 9, 3);//Canny算子
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//灰度图反转
	connect(ui.pushButton_4, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		for (size_t i = 0; i < cvImage.rows; i++)
		{
			for (size_t j = 0; j < cvImage.cols; j++)
			{
				cvImage.at<uchar>(i, j) = 255 - cvImage.at<uchar>(i, j);
			}
		}
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//对数变换
	connect(ui.pushButton_5, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		for (size_t i = 0; i < cvImage.rows; i++)
		{
			for (size_t j = 0; j < cvImage.cols; j++)
			{
				cvImage.at<uchar>(i, j) = 6*log((double)cvImage.at<uchar>(i, j)+1);//对数变换 s=6*log(r+1)
			}
		}
		cv::normalize(cvImage, cvImage, 0, 255, cv::NORM_MINMAX);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	connect(ui.pushButton_6, &QPushButton::pressed, [=]()
	{
		QImage img("../Image.bmp");
		img.save("SaveTest.png");
	});
}

ImgCvtWithCV::~ImgCvtWithCV()
{}
