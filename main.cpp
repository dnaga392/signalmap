#include <QtWidgets/QApplication>
#include "mappingwidget.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MappingWidget w;
    w.show();
    return a.exec();
}
