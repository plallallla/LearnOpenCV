#include "ImgCvtWithCV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgCvtWithCV w;
    w.show();
    return a.exec();
}
