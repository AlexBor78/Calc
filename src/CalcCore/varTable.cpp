#include <varTable.h>

namespace Calc
{
    void VarTable::setVal(const char *n, MainValType v)
    {
        if(!contain(n))
        {
            throw(CalcException("Var or const is not contain"));
        }
        table.at(std::string(n)).setVal(v);
    }

    Varible& VarTable::at(const char *s)
    {
        if(contain(s))
        {
            return table.at(s);
        }
        throw("Varible is not contain");
    }

    bool VarTable::contain(const char *n)
    {
        return table.find(std::string(n)) != table.end();
    }

    MainValType VarTable::getVal(const char *n)
    {
        if(!contain(n))
        {
            throw(CalcException("var or const is not contain"));
        }
        return table.at(std::string(n)).getVal();
    }

    void VarTable::insert(const char *n, MainValType v)
    {
        if(contain(n))
        {
            throw(CalcException("var or const is alredy used"));
        }
        table.insert({std::string(n), Varible(v)});
    }
} // namespace Calc
