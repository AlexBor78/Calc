#include <varTable.h>

namespace Calc
{
    int VarTable::setVal(const char *n, double v)
    {
        if(!contain(n))
        {
            throw(CalcException("Var or const is not contain"));
            return -1;
        }
        table.at(std::string(n)).setVal(v);
        return 0;
    }

    bool VarTable::contain(const char *n)
    {
        return table.find(std::string(n)) != table.end();
    }

    double VarTable::getVal(const char *n)
    {
        if(!contain(n))
        {
            throw(CalcException("var or const is not contain"));
            return -1;
        }
        return table.at(std::string(n)).getVal();
    }

    int VarTable::insert(const char *n, double v)
    {
        if(contain(n))
        {
            throw(CalcException("var or const is alredy used"));
            return -1;
        }
        table.insert({std::string(n), Varible(v)});
        return 0;
    }
} // namespace Calc
