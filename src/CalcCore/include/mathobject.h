#pragma once
#include <calculator.h>
#include <exception.h>

namespace Calc
{
    class MathObject
    {
    friend Constant;
    friend Varible;
    friend Function;

    private:
        bool isInit{0};
    protected:
        virtual MainValType getVal();
        bool isInited();
    protected:
        MathObject();
        ~MathObject();
    };   
} // namespace Calc
