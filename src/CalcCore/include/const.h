#pragma once
#include <calculator.h>
#include <mathobject.h>

namespace Calc
{
    class Constant : public MathObject
    {
    friend Varible;
    private:
        MainValType val{0};
    public:
        virtual MainValType getVal();
    public:
        Constant(MainValType);
        ~Constant();
    protected:
        Constant();
    };
        
} // namespace Calc
