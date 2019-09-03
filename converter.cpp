#include "converter.h"

#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>

#include <QDebug>

static bool string2int(const std::string& in, int& out)
{
    int decimal{0};
    try {
        decimal = std::stoi(in);

    } catch (...) {
        return false;
    }
    out = decimal;
    return true;
}

std::string decimalToBinar(const std::string &dec)
{
    int decimal{0};
    if(!string2int(dec, decimal)) return std::string("nan");
    if(decimal == 0) return "0";

    std::vector<int> results;
    while(decimal != 0)
    {
        results.push_back(decimal % 2);
        decimal = static_cast<int>(decimal/2);
    }

    std::stringstream result;
    std::reverse(results.begin(), results.end());
    std::copy(results.begin(), results.end(), std::ostream_iterator<int>(result, ""));
    return result.str();
}

std::string binarToDecimal(const std::string &bin)
{
    int decimal{0};
    try {
        decimal = std::stoi(bin, nullptr, 2);

    } catch (...) {
        return "nan";
    }   
    return std::to_string(decimal);
}

std::string hexToDecimal(const std::string &hex)
{
    unsigned int x{0};
    std::string tmp(hex);
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
    qDebug() << tmp.c_str();
    try
    {
        x = std::stoul(tmp, nullptr, 16);
    }
    catch(...)
    {
        return "nan";
    }
    return std::to_string(x);
}

std::string decimalToHex(const std::string &dec)
{
    std::stringstream ss; int decimal;
    if(!string2int(dec, decimal)) return std::string("nan");
    ss<< std::hex << decimal; // int decimal_value
    return(ss.str());
}

























