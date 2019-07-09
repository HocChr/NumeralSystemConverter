#include "controller.h"
#include "converter.h"

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
    qDebug() << "Decimal: " << v.c_str() << "Binär: " << decimalToBinar(v).c_str();
}

void Controller::onBinarChanged(std::string &v)
{
    qDebug() << v.c_str();
}
