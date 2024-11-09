#pragma once
#include <calculator.h>
#include <objectTable.h>
#include <const.h>

namespace Calc
{
    class ConstTable : ObjectTable
    {
    private:
        std::map<std::string, Constant> table;
    public:
        virtual bool contain(const char*);
        virtual MainValType getVal(const char*);
        virtual Constant& at(const char*);

        virtual void insert(const char*, MainValType);
    public:
        ConstTable();
        ~ConstTable();
    };
    
} // namespace Calc
