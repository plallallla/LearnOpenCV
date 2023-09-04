#include "BugDetect.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BugDetect w;
    w.show();
    return a.exec();
}
