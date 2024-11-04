#pragma once
#include <calculator.h>
#include <exception.h>

namespace Calc
{
    class StrToSolve
    {
    private:
        char *str{nullptr};
        uint32_t cursor{0};
        bool isInit{0};
    private:
        void skipSpaces();
        void checkInit();
    public:
        bool isEnd();
        bool isBegin();
        char getCh();
        // char getNextCh();

        void cursorpl();
        void cursormn();

        void setStr(const char*);
        bool isInited();
    public:
        StrToSolve(const char*);
        StrToSolve();
        ~StrToSolve();
    };
    
} // namespace Calc
