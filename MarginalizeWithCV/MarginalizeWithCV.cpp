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
		const uchar* p;													//ԭͼ��ǰ���׵�ַ����ʱ��ָ��
		const uchar* prior;												//ԭͼ��һ���׵�ַ����ʱ��ָ��
		const uchar* next;												//ԭͼ��һ���׵�ַ����ʱ��ָ��
		uchar* pNew;														//��ͼ��ǰ���׵�ַ����ʱ��ָ��
		int cols = img.cols * img.channels();					//��*ͨ����
		int rows = img.rows;											//����
		int channels = img.channels();								//ͨ����
		cv::Mat New = cv::Mat::zeros(img.size(), img.type());	//����һ�ź�ɫ��ͼ
		//���д���ÿ���׺�β��������
		for (i = 1; i < rows - 1; i++)
		{
			p = img.ptr<uchar>(i);							//ԭͼ��ǰ���׵�ַ
			prior = img.ptr<uchar>(i - 1);					//ԭͼ��һ���׵�ַ
			next = img.ptr<uchar>(i + 1);					//ԭͼ��һ���׵�ַ
			pNew = New.ptr<uchar>(i);					//��ͼ��ǰ���׵�ַ
			//���д���ÿ���׺�β��������
			for (j = 0 + channels; j <= cols - channels; j++)
			{
				pNew[j] = cv::saturate_cast<uchar>(4 * p[j] - prior[j] - next[j] - p[j - channels] - p[j + channels]);
				//				����RGB��Χ(0~255)			
				//p[j]����ǰ�е�ǰ��Ԫ��		prior[j]����һ�е�ǰ��Ԫ��		next[j]����һ�е�ǰ��Ԫ��
				// p[j - channels]����һ�����أ�����RGB��   p[j + channels]����һ�����أ�����RGB��
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
		cv::Mat New = cv::Mat::zeros(img.size(), img.type());	//����һ�ź�ɫ��ͼ
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
