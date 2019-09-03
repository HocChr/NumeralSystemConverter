#include "mainwindow.h"
#include "controller.h"
#include <QApplication>


void setConnections(Controller& c, MainWindow& w)
{
    QObject::connect(&w, SIGNAL(decimalChanged(std::string &)), &c, SLOT(onDecimalChanged(std::string &)));
    QObject::connect(&w, SIGNAL(hexChanged(std::string &))    , &c, SLOT(onHexChanged(std::string &)));
    QObject::connect(&w, SIGNAL(binarChanged(std::string &))  , &c, SLOT(onBinarChanged(std::string &)));
    QObject::connect(
        &c, SIGNAL(dataChanged(std::string &, std::string &, std::string &)), &w,
        SLOT(onDataChanged(std::string &, std::string &, std::string &)));
}

int main(int argc, char *argv[])    
{
    QApplication a(argc, argv);
    MainWindow w;
    Controller c;

    setConnections(c, w);
    w.show();
    
    return a.exec();
}
