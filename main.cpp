#include "mainwindow.h"
#include "controller.h"
#include <QApplication>


void setConnections(Controller& c, QWindow* w)
{
  //QObject::connect();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Controller c;

    w.show();

    return a.exec();
}
