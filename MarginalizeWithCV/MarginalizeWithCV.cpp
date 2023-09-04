#include "MarginalizeWithCV.h"

MarginalizeWithCV::MarginalizeWithCV(QWidget *parent)
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
		cv::Mat img = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		int i, j;
		const uchar* p;													//原图当前行首地址（暂时无指向）
		const uchar* prior;												//原图上一行首地址（暂时无指向）
		const uchar* next;												//原图下一行首地址（暂时无指向）
		uchar* pNew;														//新图当前行首地址（暂时无指向）
		int cols = img.cols * img.channels();					//列*通道数
		int rows = img.rows;											//行数
		int channels = img.channels();								//通道数
		cv::Mat New = cv::Mat::zeros(img.size(), img.type());	//创建一张黑色的图
		//按行处理（每行首和尾不做处理）
		for (i = 1; i < rows - 1; i++)
		{
			p = img.ptr<uchar>(i);							//原图当前行首地址
			prior = img.ptr<uchar>(i - 1);					//原图上一行首地址
			next = img.ptr<uchar>(i + 1);					//原图下一行首地址
			pNew = New.ptr<uchar>(i);					//新图当前行首地址
			//按列处理（每列首和尾不做处理）
			for (j = 0 + channels; j <= cols - channels; j++)
			{
				pNew[j] = cv::saturate_cast<uchar>(4 * p[j] - prior[j] - next[j] - p[j - channels] - p[j + channels]);
				//				限制RGB范围(0~255)			
				//p[j]：当前行当前列元素		prior[j]：上一行当前列元素		next[j]：下一行当前列元素
				// p[j - channels]：上一列像素（不是RGB）   p[j + channels]：下一列像素（不是RGB）
			}
		}
		cv::cvtColor(New, New, cv::COLOR_BGR2RGB);
		QImage qImage(New.data, New.cols, New.rows, static_cast<int>(New.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
	connect(ui.pushButton_3, &QPushButton::pressed, [=]()
	{
		cv::Mat img = cv::imread("../LenaRGB.bmp", cv::IMREAD_COLOR);
		cv::Mat New = cv::Mat::zeros(img.size(), img.type());	//创建一张黑色的图
		cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
		cv::filter2D(img, New, img.depth(), kernel);
		cv::cvtColor(New, New, cv::COLOR_BGR2RGB);
		QImage qImage(New.data, New.cols, New.rows, static_cast<int>(New.step), QImage::Format_RGB888);
		ui.graphicsView->OpenImage(qImage);
		ui.graphicsView->FitImage();
	});
}

MarginalizeWithCV::~MarginalizeWithCV()
{}
