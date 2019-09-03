#include "controller.h"
#include "converter.h"

Controller::Controller()
{

}

void Controller::onHexChanged(std::string& v)
{
    auto decimal = hexToDecimal(v);
    auto binar = decimalToBinar(decimal);
    emit dataChanged(decimal, binar, v);
}

void Controller::onDecimalChanged(std::string& v)
{
    auto binar = decimalToBinar(v);
    auto hex   = decimalToHex(v);
    emit dataChanged(v, binar, hex);
}

void Controller::onBinarChanged(std::string &v)
{
    auto decimal = binarToDecimal(v);
    auto hex = decimalToHex(decimal);
    emit dataChanged(decimal, v, hex);
}
