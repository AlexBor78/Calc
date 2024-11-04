#pragma once
#include <calculator.h>

namespace Calc
{
    class CalcException : public std::exception
    {
    private:
        char* w;
    public:
        CalcException(const char*);
        virtual const char *what() const noexcept override;
    };
    
} // namespace Calc
