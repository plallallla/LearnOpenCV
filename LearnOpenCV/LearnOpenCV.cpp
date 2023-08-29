#include "LearnOpenCV.h"
#include <opencv/cv.h>
#ifdef QT_DEBUG
#pragma comment(lib,"opencv_world3411d.lib")
#else
#pragma comment(lib,"opencv_world3411.lib")
#endif


LearnOpenCV::LearnOpenCV(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	cv::Mat img;
}

LearnOpenCV::~LearnOpenCV()
{}
