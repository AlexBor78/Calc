#include <constTable.h>

namespace Calc
{
    ConstTable::ConstTable() = default;
    ConstTable::~ConstTable() = default;
    
    bool ConstTable::contain(const char *n)
    {
        return table.find(std::string(n)) != table.end();
    }

    double ConstTable::getVal(const char *n)
    {
        if(!contain(n))
        {
            throw(CalcException("var or const is not contain"));
            return -1;
        }
        return table.at(std::string(n)).getVal();
    }

    int ConstTable::insert(const char *n, double v)
    {
        if(contain(n))
        {
            throw(CalcException("var or const is alredy used"));
            return -1;
        }
        table.insert({std::string(n), Constant(v)});
        return 0;
    }
    
} // namespace Calc
