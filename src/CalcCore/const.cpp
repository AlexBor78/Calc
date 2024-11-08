#include <const.h>

namespace Calc
{
    Constant::~Constant() = default;
    Constant::Constant() = default;
    Constant::Constant(MainValType v)
    :
    val(v),
    MathObject()
    {
        isInit = 1;
    }

    MainValType Constant::getVal()
    {
        if(isInit)
        {
            return val;
        }
        throw(CalcException("Const or Var is not inited"));
    }

} // namespace Calc
