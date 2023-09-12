#include "BugDetect.h"

#include <qDebug>

BugDetect::BugDetect(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	//ԭͼ
	connect(ui.pushButton, &QPushButton::pressed, [=]() 
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//�Ҷ�ͼ
	connect(ui.pushButton_2, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//����
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../bug.png", cv::IMREAD_COLOR);
		cv::cvtColor(cvImage, cvImage, cv::COLOR_BGR2GRAY);
		cv::blur(cvImage, cvImage, cv::Size(3, 3));
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	//�ݶ�ͼ
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		show8Gray(cvImage);

	});
	//�ٽ���
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);
		show8Gray(cvImage);

	});
	//��̬ѧ
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//��ֵ������
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//�Զ����
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//�ղ���
		show8Gray(cvImage);
	});
	//ϸ�ڿ̻�
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//��ֵ������
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//�Զ����
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//�ղ���
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::erode(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		cv::dilate(cvImage, cvImage, kernel, cv::Point(-1, -1), 4);
		show8Gray(cvImage);

	});
	//��������
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//��ֵ������
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//�Զ����
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//�ղ���
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
	//��������
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//��ֵ������
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//�Զ����
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//�ղ���
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
	//�ü�
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
		cv::convertScaleAbs(cvImage, cvImage);//������ͼ�������ֵ���ݸ������������Ӻ�ƫ�����������Ա任��Ȼ��ȡ����ֵ
		cv::GaussianBlur(cvImage, cvImage, cv::Size(9, 9), 0);
		cv::threshold(cvImage, cvImage, 90, 255, cv::THRESH_BINARY);//��ֵ������
		auto k = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25));//�Զ����
		cv::morphologyEx(cvImage, cvImage, cv::MORPH_CLOSE, k);//�ղ���
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
