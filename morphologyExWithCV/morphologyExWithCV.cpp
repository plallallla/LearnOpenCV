#include "morphologyExWithCV.h"

int val;

#include <qDebug>

morphologyExWithCV::morphologyExWithCV(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_2, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(ui.horizontalSlider->value(), ui.horizontalSlider->value()));
		cv::dilate(cvImage, cvImage, k);
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../LenaRGB.bmp");
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(ui.horizontalSlider->value(), ui.horizontalSlider->value()));
		cv::erode(cvImage, cvImage, k);
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_4, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../te.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11));
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_OPEN, k);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_5, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../te.bmp");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11));
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_6, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../shapes_and_colors.jpg");
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
		cv::Mat erode_out;
		cv::erode(cvImage, erode_out, k);
		cv::subtract(cvImage, erode_out, cvImage);
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_7, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../shapes_and_colors.jpg");
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));
		cv::Mat erode_out;
		cv::dilate(cvImage, erode_out, k);
		cv::subtract(erode_out, cvImage, cvImage);
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_8, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../shapes_and_colors.jpg");
		ShowRGB(cvImage);
	});
	connect(ui.pushButton_9, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../shapes_and_colors.jpg");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		cv::Mat X = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(cvImage.cols / 32, 1));
		cv::Mat dImage;
		cv::Mat eImage;
		cv::dilate(cvImage, dImage, X);
		cv::erode(cvImage, eImage, X);
		cv::subtract(dImage, eImage, cvImage);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_10, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../shapes_and_colors.jpg");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		cv::Mat X = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, cvImage.rows / 32));
		cv::Mat dImage;
		cv::Mat eImage;
		cv::dilate(cvImage, dImage, X);
		cv::erode(cvImage, eImage, X);
		cv::subtract(dImage, eImage, cvImage);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_11, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../rings.png");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_12, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../rings.png");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::threshold(cvImage, cvImage, 0, 255, cv::THRESH_OTSU);
		ShowGray(cvImage);
	});
	connect(ui.pushButton_13, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../rings.png");
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::Mat k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_BLACKHAT, k);
		cv::threshold(cvImage, cvImage, 0, 255, cv::THRESH_OTSU);
		cv::Mat kk = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, kk);
		ShowGray(cvImage);
	});
}

morphologyExWithCV::~morphologyExWithCV()
{}

void morphologyExWithCV::ShowRGB(const cv::Mat & img)
{
	QImage qImage(img.data, img.cols, img.rows, static_cast<int>(img.step), QImage::Format_RGB888);
	cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
	ui.graphicsView->OpenImage(qImage);
	ui.graphicsView->FitImage();
}

void morphologyExWithCV::ShowGray(const cv::Mat & img)
{
	QImage qImage(img.data, img.cols, img.rows, static_cast<int>(img.step), QImage::Format_Grayscale8);
	ui.graphicsView->OpenImage(qImage);
	ui.graphicsView->FitImage();
}
