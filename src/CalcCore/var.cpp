#include <var.h>

namespace Calc
{
    Varible::Varible(double v)
    :
    val(v),
    isInit(1){}

    void Varible::setVal(double v)
    {
        val = v;
        isInit = 1;
    }

    double Varible::getVal()
    {
        if(isInit)
        {
            return val;
        }
        throw(CalcException("var is not inited"));
    }
} // namespace Calc
