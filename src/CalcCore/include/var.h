#pragma once
#include <calculator.h>
#include <const.h>

namespace Calc
{
    class Varible : public Constant
    {
    public:
        void setVal(MainValType);
    public:
        Varible(MainValType);
        Varible();
        ~Varible();
    };
    
} // namespace Calc
