#include "MarginalizeWithCV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MarginalizeWithCV w;
    w.show();
    return a.exec();
}
