#include <strtosolve.h>

namespace Calc
{
    StrToSolve::StrToSolve() = default;
    StrToSolve::StrToSolve(const char *s)
    :
    isInit(1)
    {
        str = new char[strlen(s)];
        strcpy(str, s);
    }
    
    StrToSolve::~StrToSolve()
    {
        if(isInit)
        {
            delete[] str;
        }
    }

    void StrToSolve::checkInit()
    {
        if(!isInit)
        {
            throw(CalcException("str is not inited"));
        }
    }

    void StrToSolve::skipSpaces()
    {
        checkInit();
        while(isspace(str[cursor]) && str[cursor])
        {
            ++cursor;
        }
    }

    bool StrToSolve::isEnd()
    {
        checkInit();
        return str[cursor] == 0;
    }

    bool StrToSolve::isBegin()
    {
        return cursor == 0;
    }

    bool StrToSolve::isInited()
    {
        return isInit;
    }

    char StrToSolve::getCh()
    {
        checkInit();
        skipSpaces();
        return str[cursor];
    }

    void StrToSolve::cursorpl()
    {
        checkInit();
        if(isEnd())
        {
            throw(CalcException("can not increase cursor, because is end of str"));
            return;
        }
        ++cursor;
    }

    void StrToSolve::cursormn()
    {
        checkInit();
        if(isBegin())
        {
            throw(CalcException("can not decrease cursor, because is begin of str"));
            return;
        }
        --cursor;
    }

    void StrToSolve::setStr(const char *s)
    {
        if(isInit)
        {
            delete[] str;
        }
        str = new char[strlen(s)];
        strcpy(str, s);
        isInit = 1;
        cursor = 0;
        // std::cout << "got str: " << str << std::endl;
    }
} // namespace Calc
