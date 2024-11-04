#pragma once
#include <calculator.h>
#include <constTable.h>
#include <var.h>

namespace Calc
{
    class VarTable //: public ConstTable
    {
    private:
        std::map<std::string, Varible> table;
    public:
        virtual bool contain(const char*);
        virtual double getVal(const char*);
        virtual int setVal(const char*, double);

        virtual int insert(const char*, double);
    };
    
} // namespace Calc
