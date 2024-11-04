#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <cstdint>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

namespace Calc
{
    namespace Math
    {
        double factorial(double);
    } // namespace Math

    enum TokenValue : char;
    class CalcException;
    class StrToSolve;

    class Constant;
    class ConstTable;

    class Varible;
    class VarTable;

    class Function;  // not realesed
    class FuncTable; // not realesed


    class Calc;

} // namespace Calc
