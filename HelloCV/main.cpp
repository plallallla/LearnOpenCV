#include "HelloCV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloCV w;
    w.show();
    return a.exec();
}
