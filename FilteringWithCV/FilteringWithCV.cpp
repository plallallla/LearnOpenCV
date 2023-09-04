#include "FilteringWithCV.h"

FilteringWithCV::FilteringWithCV(QWidget *parent)
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
	connect(ui.pushButton_2, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::blur(cvImage, cvImage, cv::Size(3, 3));
		ShowImg(cvImage);
		//if (ui.checkBox->isChecked())
		//{
		//	//获取图像直方图
		//	cv::Mat hist;
		//	int histsize = 256;
		//	float ranges[] = { 0,256 };
		//	const float* histRanges = { ranges };
		//	cv::calcHist(&cvImage, 1, 0, cv::Mat(), hist, 1, &histsize, &histRanges);
		//	//创建直方图显示图像
		//	int hist_h = 300;//直方图的图像的高
		//	int hist_w = 512; //直方图的图像的宽
		//	int bin_w = hist_w / histsize;//直方图的等级
		//	cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));//绘制直方图显示的图像
		//	normalize(hist, hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());//归一化直方图
		//	for (int i = 1; i < histsize; i++)
		//	{
		//		line(histImage, cv::Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))),
		//			cv::Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), cv::Scalar(0, 255, 0), 2, 8, 0);
		//	}
		//	QImage qImage(histImage.data, histImage.cols, histImage.rows, static_cast<int>(histImage.step), QImage::Format_RGB888);
		//	ui.graphicsView->OpenImage(qImage);
		//	ui.graphicsView->FitImage();
		//}
		//else
		//{
		//	QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		//	ui.graphicsView->OpenImage(qImage);
		//	ui.graphicsView->FitImage();
		//}
	});
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(3, 3), 1);
		ShowImg(cvImage);
	});
	connect(ui.pushButton_4, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::medianBlur(cvImage, cvImage, 3);
		ShowImg(cvImage);
	});
	connect(ui.pushButton_4, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::medianBlur(cvImage, cvImage, 3);
		ShowImg(cvImage);
	});
	connect(ui.pushButton_5, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		ShowImg(cvImage);
	});
}

FilteringWithCV::~FilteringWithCV()
{}

void FilteringWithCV::ShowImg(cv::Mat &cvImage)
{
	if (ui.checkBox->isChecked())
	{
		//获取图像直方图
		cv::Mat hist;
		int histsize = 256;
		float ranges[] = { 0,256 };
		const float* histRanges = { ranges };
		cv::calcHist(&cvImage, 1, 0, cv::Mat(), hist, 1, &histsize, &histRanges);
		//创建直方图显示图像
		int hist_h = 300;//直方图的图像的高
		int hist_w = 512; //直方图的图像的宽
		int bin_w = hist_w / histsize;//直方图的等级
		cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));//绘制直方图显示的图像
		normalize(hist, hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());//归一化直方图
		for (int i = 1; i < histsize; i++)
		{
			line(histImage, cv::Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))),
				cv::Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), cv::Scalar(0, 255, 0), 2, 8, 0);
		}
		QImage qImage(histImage.data, histImage.cols, histImage.rows, static_cast<int>(histImage.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	}
	else
	{
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	}
}
