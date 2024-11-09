#include <calc.h>

namespace Calc
{
    Calc::Calc()= default;
    Calc::~Calc() = default;
    
    // public functions
    std::vector<MainValType> Calc::calculate(const char *s)
    {
        str.setStr(s);
        solutions.clear();
        while (1)
        {
            getToken();
            if(currTok == END)
            {
                break;
            }
            if(currTok == PRINT)
            {
                continue;
            }
            MainValType buf = expr();
            if(!isError && !newName)
            {
                solutions.push_back(buf);
            }
            newName = 0;
            isError = 0;
        }
        return solutions;
    }

    void Calc::inserVar(const char *n, MainValType v)
    {
        if(varTable.contain(n))
        {
            throw("var is alredy use");
            return;
        }
        varTable.insert(n, v);
    }

    void Calc::inserConst(const char *n, MainValType v)
    {
        if(constTable.contain(n))
        {
            throw("var is alredy use");
            return;
        }
        constTable.insert(n, v);
    }
    ////////////////////////


    // error handings
    void Calc::error(const char *s)
    {
        std::cout << s << std::endl;
        isError = 1;
    }
    void Calc::error(std::string s)
    {
        std::cout << s << std::endl;
        isError = 1;
    }
    ////////////////////


    // calculator

    TokenValue Calc::getToken()
    {
        // std::cout << "getToken()" << std::endl;
        char ch{0};
        std::string buf;
        
        ch = str.getCh();
        // while(ch == ' ')
        // {
        //     ch = str.getCh();
        // }

        do
        {
            if(str.isEnd())
            {
                return currTok = END;
            }
        } while (ch != '\n' && isspace(ch));

        switch (ch)
        {
        case (';'): case ('\n'):
            str.cursorpl();
            return currTok = PRINT;
            break;

        case ('+'): case('*'): case('-'): case('/'): case('^'): case('!'): case('='): case('('): case(')'): case('|'): // case(','): case('{'): case('}')
            str.cursorpl();
            return currTok = (TokenValue)(ch);
            break;

        case ('0'): case('1'): case('2'): case('3'): case('4'): case('5'): case('6'): case('7'): case('8'): case('9'):
            while (isdigit(ch))
            {
                buf += ch;
                str.cursorpl();
                ch = str.getCh();
            }
            if(ch == '.')
            {
                str.cursorpl();
                ch = str.getCh();

                var_val = std::stold(buf);
                
                buf.clear();

                while (isdigit(ch))
                {
                    buf += ch;
                    str.cursorpl();
                    ch = str.getCh();
                }
                var_val = var_val + std::stold(buf) / pow(10, buf.size());
                return currTok = NUMBER;
            }
            // std::cout << "num:" << buf << std::endl;
            var_val = std::stold(buf);
            return currTok = NUMBER;
            break;

        default:
            if(isalpha(ch))
            {
                while (isalpha(ch) && !isspace(ch))
                {
                    buf += ch;
                    str.cursorpl();
                    ch = str.getCh();
                    // std::cout << "buf: " << buf << std::endl;
                    if(buf == "const")
                    {
                        break;
                    }
                }
                if(buf == "const")
                {
                    buf.clear();
                    return currTok = CONST;

                }
                if(var_name != nullptr)
                {
                    delete[] var_name;
                }
                var_name = new char[buf.size()];
                strcpy(var_name, buf.c_str());
                // std::cout << "var name: " << var_name << std::endl;
                return currTok = NAME;
            }
            error(std::string("bad token") + ch);
            str.cursorpl();
            return currTok = PRINT;
            break;
        }
    }

    MainValType Calc::newLvl()
    {
        // std::cout << "newLvl()" << std::endl;
        MainValType left = prim();
        while (1)
        {
            switch (currTok)
            {
            case (EXPONEN):
                getToken();
                left = pow(left, prim());
                break;

            case (FACTORIAL):
                getToken();
                left = Math::factorial(left);
                break;
            
            default:
                return left;
                break;
            }
        }
        
    }

    MainValType Calc::term()
    {
        // std::cout << "term()" << std::endl;
        MainValType left = newLvl();
        while(1)
        {
            switch (currTok)
            {
            case (MUL):
                getToken();
                left *= newLvl();
                break;

            case (DIV):
            {
                getToken();
                MainValType d = newLvl();
                if(d==0)
                {
                    error("devid by 0");
                }
                left /= d;
            } break;
            
            default:
                return left;
                break;
            }
        }
    }

    MainValType Calc::expr()
    {
        // std::cout << "expr()" << std::endl;
        MainValType left = term();
        while (1)
        {
            switch (currTok)
            {
            case (PLUS):
                getToken();
                left += term();
                break;

            case (MINUS):
                getToken();
                left -= term();
                break;
            
            default:
                return left;
                break;
            }
        }
        
    }

    MainValType Calc::prim()
    {
        // std::cout << "prim()" << std::endl;
        switch (currTok)
        {
        case (MINUS):
            getToken();
            return -prim();
            break;

        case (NUMBER):
            getToken();
            return var_val;
            break;

        case (LP):
        {
            getToken(); 
            MainValType e = expr();
            if(currTok != RP)
            {
                error("expected ')'");
                return -1;
            }
            getToken();
            return e;
        } break;

        case (MODULE):
        {
            getToken(); 
            MainValType e = expr();
            if(currTok != MODULE)
            {
                error("expected '|'");
                return -1;
            }
            getToken();
            return fabs(e);
        } break;

        case(CONST):
            // std::cout << "case(const):" << std::endl;
            getToken();
            if(constTable.contain(var_name))
            {
                if(getToken() == ASSIGN)
                {
                    error("Constant is unchenged");
                    getToken();
                    return -1;
                }
                return constTable.getVal(var_name);
            }
            if(getToken() == ASSIGN)
            {
                // std::cout << "New const" << std::endl;
                std::string buf(var_name);
                getToken();
                newName = 1;
                constTable.insert(buf.c_str(), expr());
                return 0;
            }

        case (NAME):
            if(constTable.contain(var_name))
            {
                if(getToken() == ASSIGN)
                {
                    error("constants is unchenged");
                    getToken();
                    return -1;
                }
                return constTable.getVal(var_name);
            }
            if(getToken() == ASSIGN)
            {
                std::string buf(var_name);
                getToken();
                newName = 1;
                if(varTable.contain(var_name))
                {
                    varTable.setVal(buf.c_str(), expr());
                    // return varTable.getVal(buf.c_str());
                    return 0;
                }
                varTable.insert(buf.c_str(), expr());
                // return varTable.getVal(buf.c_str());
                return 0;
            }
            if(varTable.contain(var_name))
            {
                return varTable.getVal(var_name);
            }
            error(std::string("unknow varible ") + var_name);
            return -1;
            break;
        
        default:
            error("unknow symbol");
            return -1;
            break;
        }
    }

} // namespace Calc
