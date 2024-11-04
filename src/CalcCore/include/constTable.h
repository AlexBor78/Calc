#pragma once
#include <calculator.h>
#include <exception.h>
#include <const.h>
#include <var.h>

namespace Calc
{
    class ConstTable
    {
    private:
        std::map<std::string, Constant> table;
    public:
        virtual bool contain(const char*);
        virtual double getVal(const char*);

        virtual int insert(const char*, double);
    public:
        ConstTable();
        ~ConstTable();
    };
    
} // namespace Calc

