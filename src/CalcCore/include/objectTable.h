#pragma once
#include <calculator.h>
#include <exception.h>

namespace Calc
{
    class ObjectTable
    {
    friend ConstTable;
    friend FuncTable;
    friend VarTable;
    public:
        virtual bool contain(const char*);
        virtual void insert(const char*, MainValType);
        virtual MainValType getVal(const char*);
    protected:
       ~ObjectTable();
       ObjectTable();
    };
} // namespace Calc
