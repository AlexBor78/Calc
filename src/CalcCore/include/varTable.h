#pragma once
#include <calculator.h>
#include <constTable.h>
#include <var.h>

namespace Calc
{
    class VarTable : public ConstTable
    {
    private:
        std::map<std::string, Varible> table;
    public:
        virtual bool contain(const char*);
        virtual MainValType getVal(const char*);
        virtual void setVal(const char*, MainValType);
        virtual Varible& at(const char*);

        virtual void insert(const char*, MainValType);
    };
    
} // namespace Calc
