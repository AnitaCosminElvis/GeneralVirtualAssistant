#include "Views/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.Initialize();
    w.show();

    return a.exec();
}
