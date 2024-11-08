#include <var.h>

namespace Calc
{
    Varible::~Varible() = default;
    Varible::Varible() = default;
    Varible::Varible(MainValType v)
    :
    Constant(v){}

    void Varible::setVal(MainValType v)
    {
        val = v;
        isInit = 1;
    }

} // namespace Calc
