#include "BugDetect.h"

#include <qDebug>

BugDetect::BugDetect(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	//原图
	connect(ui.pushButton, &QPushButton::pressed, [=]() 
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//灰度图
	connect(ui.pushButton_2, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//降噪
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::blur(cvImage, cvImage, cv::Size(3, 3));
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//梯度图
	connect(ui.pushButton_4, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		show8Gray(cvImage);

	});
	//再降噪
	connect(ui.pushButton_5, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		show8Gray(cvImage);

	});
	//形态学
	connect(ui.pushButton_6, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//阈值化处理
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//自定义核
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//闭操作
		show8Gray(cvImage);
	});
	//细节刻画
	connect(ui.pushButton_7, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//阈值化处理
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//自定义核
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//闭操作
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::erode(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		cv::dilate(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		show8Gray(cvImage);

	});
	//查找轮廓
	connect(ui.pushButton_8, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//阈值化处理
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//自定义核
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//闭操作
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::erode(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		cv::dilate(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(cvImage.clone(), contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

		QVector<QPointF> polygon;

		for (size_t i = 0; i < contours.size(); i++)
		{
			for (size_t j = 0; j < contours[i].size(); j++)
			{
				qDebug() << QString("[%0,%1]:").arg(i).arg(j) << contours[i][j].x << "," << contours[i][j].y << ";";
				polygon << QPointF{ (qreal)contours[i][j].x, (qreal)contours[i][j].y };
			}
		}
		ui.graphicsView->ClearItems();
		ui.graphicsView->DrawPolygon(polygon);
		//qDebug() << contours;
		//qDebug() << hierarchy;
		show8Gray(cvImage);

	});
	//绘制轮廓
	connect(ui.pushButton_9, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//阈值化处理
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//自定义核
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//闭操作
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::erode(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		cv::dilate(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(cvImage.clone(), contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		QVector<QPointF> polygon;
		for (size_t i = 0; i < contours.size(); i++)
		{
			for (size_t j = 0; j < contours[i].size(); j++)
			{
				qDebug() << QString("[%0,%1]:").arg(i).arg(j) << contours[i][j].x << "," << contours[i][j].y << ";";
				polygon << QPointF{ (qreal)contours[i][j].x, (qreal)contours[i][j].y };
			}
		}
		ui.graphicsView->ClearItems();
		ui.graphicsView->DrawRect(QPolygonF(polygon).boundingRect());
		show8Gray(cvImage);

	});
	//裁剪
	connect(ui.pushButton_10, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::Mat xImg;
		cv::Mat yImg;
		cv::Sobel(cvImage, xImg, CV_32F, 1, 0);
		cv::Sobel(cvImage, yImg, CV_32F, 0, 1);
		cv::subtract(xImg, yImg, cvImage);
		//cv::addWeighted(xImg, 0.5, yImg, 0.5, 0, cvImage);
		cv::convertScaleAbs(cvImage, cvImage);//将输入图像的像素值根据给定的缩放因子和偏移量进行线性变换，然后取绝对值
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//阈值化处理
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//自定义核
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//闭操作
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::erode(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		cv::dilate(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(cvImage.clone(), contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		QVector<QPointF> polygon;
		for (size_t i = 0; i < contours.size(); i++)
		{
			for (size_t j = 0; j < contours[i].size(); j++)
			{
				qDebug() << QString("[%0,%1]:").arg(i).arg(j) << contours[i][j].x << "," << contours[i][j].y << ";";
				polygon << QPointF{ (qreal)contours[i][j].x, (qreal)contours[i][j].y };
			}
		}
		cv::Mat oriImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(oriImage, oriImage, cv::COLOR_BGR2RGB);
		QImage qImage(oriImage.data, oriImage.cols, oriImage.rows, static_cast<int>(oriImage.step), QImage::Format_RGB888);
		ui.graphicsView->ClearItems();
		ui.graphicsView->OpenImage(qImage.copy(QPolygonF(polygon).boundingRect().toRect()));
		ui.graphicsView->FitImage();

	});
}

BugDetect::~BugDetect()
{}

void BugDetect::show8Gray(const cv::Mat & img)
{
	QImage qImage(img.data, img.cols, img.rows, static_cast<int>(img.step), QImage::Format_Grayscale8);
	//bool rlt = qImage.save("../bit.png");
	ui.graphicsView->OpenImage(qImage);
	ui.graphicsView->FitImage();
}
