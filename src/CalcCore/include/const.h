#pragma once
#include <calculator.h>
#include <exception.h>

namespace Calc
{
    class Constant
    {
    private:
        double val{0};
        bool isInit{0};
    public:
        double getVal();
        bool isInited();
    public:
        Constant(double);
        // Constant();
        ~Constant();
    };
        
} // namespace Calc
