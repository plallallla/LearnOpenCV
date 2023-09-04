#include "HistogramWithCV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HistogramWithCV w;
    w.show();
    return a.exec();
}
