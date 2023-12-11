#include "ImgGrayOut.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgGrayOut w;
    w.show();
    return a.exec();
}
