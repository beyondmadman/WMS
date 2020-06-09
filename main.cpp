#include "wmswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WMSWidget w;
    w.show();

    return a.exec();
}
