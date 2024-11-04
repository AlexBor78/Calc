#pragma once
#include <calculator.h>
#include <const.h>

namespace Calc
{
    class Varible //: public Constant
    {
    private:
        double val{0};
        bool isInit{0};
    public:
        double getVal();
        void setVal(double);
        Varible(double);
    };
    
} // namespace Calc
