#include "controller.h"

#include <QDebug>

Controller::Controller()
{

}

void Controller::onHexChanged(std::string& v)
{
    qDebug() << v.c_str();
}

void Controller::onDecimalChanged(std::string& v)
{
    qDebug() << v.c_str();
}

void Controller::onBinarChanged(std::string &v)
{
    qDebug() << v.c_str();
}
