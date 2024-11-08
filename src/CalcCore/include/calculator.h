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
    using MainValType = long double;
    enum TokenValue : char;

    class Calc;

    namespace Math
    {
        double factorial(MainValType);
    } // namespace Math

    class CalcException;
    class StrToSolve;

    class MathObject;
    class ObjectTable;

    class Constant;
    class ConstTable;

    class Varible;
    class VarTable;

    class Function;  // not realesed
    class FuncTable; // not realesed

} // namespace Calc
