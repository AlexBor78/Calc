#include <objectTable.h>

namespace Calc
{
    ObjectTable::ObjectTable() = default;
    ObjectTable::~ObjectTable() = default;

    bool ObjectTable::contain(const char *s)
    {
        throw(CalcException("Class ::Calc::ObjectTable not for using"));
    }

    void ObjectTable::insert(const char *s, MainValType v)
    {
        throw(CalcException("Class ::Calc::ObjectTable not for using"));
    }

    MainValType ObjectTable::getVal(const char *s)
    {
        throw(CalcException("Class ::Calc::ObjectTable not for using"));
        throw(CalcException(""));
    }

} // namespace Calc
