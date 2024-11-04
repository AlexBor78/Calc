#include <const.h>

namespace Calc
{
    Constant::~Constant() = default;
    // Constant::Constant() = default;
    Constant::Constant(double v)
    :
    val(v),
    isInit(1){}

    double Constant::getVal()
    {
        if(isInit)
        {
            return val;
        }
        throw(CalcException("Const is not inited"));
    }

    bool Constant::isInited()
    {
        return isInit;
    }

} // namespace Calc
