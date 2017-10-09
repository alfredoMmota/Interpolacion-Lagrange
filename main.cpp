#include "interpolacion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interpolacion w;
    w.show();

    return a.exec();
}
