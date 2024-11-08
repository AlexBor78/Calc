#include <mathobject.h>

namespace Calc
{
    MathObject::~MathObject() = default;
    MathObject::MathObject() = default;

    MainValType MathObject::getVal()
    {
        throw(CalcException("Override function ::Calc::MathObject::getVal()"));
    }

    bool MathObject::isInited()
    {
        return isInit;
    }
    
} // namespace Calc
