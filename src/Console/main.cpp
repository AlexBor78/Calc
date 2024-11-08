#include <calculator.h>
#include <iostream>
#include <calc.h>

void print(const std::vector<Calc::MainValType> &v)
{
    std::cout << "Answers: ";
    for(Calc::MainValType x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void commProccess(std::string &x)
{
    x.at(0) = ' ';
    system(x.c_str());
}

int main()
{
    Calc::Calc calc;
    std::string buf;
    std::vector<Calc::MainValType> answ;

    calc.inserVar("pasHalochka", 1941);
    calc.inserConst("pi", 3.14);
    
    while (1)
    {
        answ.clear();
        std::getline(std::cin, buf);
        if(buf.empty())
        {
            continue;
        }
        if(buf == ":exit" || buf == ":q")
        {
            break;
        }

        if(buf.at(0) == ':')
        {
            commProccess(buf);
            continue;
        }

        answ = calc.calculate(buf.c_str());
        
        if(!answ.empty())
        {
            print(answ);
            continue;
        }
    }
    return 0;
}
