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
        std::vector<MainValType> solutions{};
        TokenValue currTok{NOTINITED};
        MainValType var_val{0};
        char *var_name{nullptr};
        bool isError{0};
        bool newName{0};
    private:
        TokenValue getToken();

        void error(const char*);
        void error(std::string);

        // lvl of exponen and factorial
        MainValType newLvl();

        // lvl of multyply and diving
        MainValType term();

        // lvl of addition and subtraction
        MainValType expr();

        // return value
        MainValType prim();
    public:
        std::vector<MainValType> calculate(const char*);
        void inserVar(const char*, MainValType);
        void inserConst(const char*, MainValType);
    public:
        Calc();
        ~Calc();
    };
} // namespace Calc
