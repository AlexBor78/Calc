#include <constTable.h>

namespace Calc
{
    ConstTable::~ConstTable() = default;
    ConstTable::ConstTable() = default;
    
    bool ConstTable::contain(const char *n)
    {
        return table.find(std::string(n)) != table.end();
    }

    Constant& ConstTable::at(const char *s)
    {
        if(contain(s))
        {
            return table.at(std::string(s));
        }
        throw(CalcException("var or const is not contain"));
    }

    MainValType ConstTable::getVal(const char *n)
    {
        if(!contain(n))
        {
            throw(CalcException("var or const is not contain"));
            return -1;
        }
        return table.at(std::string(n)).getVal();
    }

    void ConstTable::insert(const char *n, MainValType v)
    {
        if(contain(n))
        {
            throw(CalcException("var or const is alredy used"));
        }
        table.insert({std::string(n), Constant(v)});
    }
    
} // namespace Calc
