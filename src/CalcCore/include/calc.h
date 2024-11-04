#pragma once
#include <calculator.h>
#include <tokenValue.h>
#include <constTable.h>
#include <strtosolve.h>
#include <varTable.h>

namespace Calc
{
    class Calc
    {
    private:
        StrToSolve str;
        VarTable varTable;
        ConstTable constTable;
        std::vector<double> solutions{};
        TokenValue currTok{NOTINITED};
        double var_val{0};
        char *var_name{nullptr};
        bool isError{0};
        bool newName{0};
    private:
        TokenValue getToken();

        void error(const char*);
        void error(std::string);

        // lvl of exponen and factorial
        double newLvl();

        // lvl of multyply and diving
        double term();

        // lvl of addition and subtraction
        double expr();

        // return value
        double prim();
    public:
        std::vector<double> calculate(const char*);
        void inserVar(const char*, double);
        void inserConst(const char*, double);
    public:
        Calc();
        ~Calc();
    };
} // namespace Calc
