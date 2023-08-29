#include "HelloCV.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include "../../include/GBmp.hpp"
#include <qDebug>

QImage convert_to_rgba(const QImage& image) {
	//if (image.format() != QImage::Format_RGB32) {
	//	qDebug() << "Image format is not RGB32.";
	//	return QImage();
	//}

	int width = image.width();
	int height = image.height();
	QImage rgba_image(width, height, QImage::Format_RGBA8888);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			QRgb rgb_pixel = image.pixel(x, y);
			QRgb rgba_pixel = qRgba(qRed(rgb_pixel), qGreen(rgb_pixel), qBlue(rgb_pixel), 255);
			rgba_image.setPixel(x, y, rgba_pixel);
		}
	}

	return rgba_image;
}

HelloCV::HelloCV(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::pressed, [=]()
	{
		cv::Mat cvImage = cv::imread("../1.bmp", cv::IMREAD_ANYDEPTH);
		QImage qImage(cvImage.data, cvImage.cols, cvImage.rows, static_cast<int>(cvImage.step), QImage::Format_RGB888);
		//ui.graphicsView->OpenImage(qImage);
		//ui.graphicsView->OpenImage(QImage("../2.bmp"));
		qDebug() << QImage("../2.bmp").format();


		int w, h, d;
		uchar *data = stbi_load("../2.bmp", &w, &h, &d, 0);
		//uchar *data = stbi_load("../red.bmp", &w, &h, &d, 0);
		//uchar *data = stbi_load("../green.bmp", &w, &h, &d, 0);
		//uchar *data = stbi_load("../blue.bmp", &w, &h, &d, 0);
		//QImage sImage(data, w, h, w*d, QImage::Format_RGB32);
		QImage sImage(data, w, h, w*d, QImage::Format_RGBA8888);


		ui.graphicsView->OpenImage(sImage);
		ui.graphicsView->FitImage();
	});
	

}

HelloCV::~HelloCV()
{}
