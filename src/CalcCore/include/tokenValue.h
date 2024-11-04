#pragma once
#include <calculator.h>

namespace Calc
{
        enum TokenValue : char
        {
            NOTINITED = -1,
            NAME,
            NUMBER,
            FUNCTOIN,
            END,
            PLUS = '+',
            MINUS = '-',
            MUL = '*',
            DIV = '/',
            EXPONEN = '^',
            FACTORIAL = '!',
            ASSIGN = '=',
            COMMA = ',',
            PRINT = ';',
            MODULE = '|',
            LP = '(',
            RP = ')'
            // LB = '{',
            // RB = '}'
        };
} // namespace Calc
