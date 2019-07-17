#include "controller.h"
#include "converter.h"

#include <QDebug>

Controller::Controller()
{

}

void Controller::onHexChanged(std::string& v)
{
    auto decimal = hexToDecimal(v);
    auto binar = decimalToBinar(decimal);
    qDebug() << "Hex: " << v.c_str() << "Decimal: " << decimal.c_str();
    qDebug() << "Hex: " << v.c_str() << "Binar: "   << binar.c_str();
}

void Controller::onDecimalChanged(std::string& v)
{
    auto binar = decimalToBinar(v);
    auto hex = decimalToHex(v);
    qDebug() << "Decimal: " << v.c_str() << "Binär: " << binar.c_str();
    qDebug() << "Decimal: " << v.c_str() << "Hex: "   << hex.c_str();
}

void Controller::onBinarChanged(std::string &v)
{
    auto decimal = binarToDecimal(v);
    auto hex = decimalToHex(decimal);
    qDebug() << "Binar: " << v.c_str() << "Decimal: " << decimal.c_str();
    qDebug() << "Binar: " << v.c_str() << "Hex: "     << hex.c_str();
}
