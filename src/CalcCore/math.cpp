#include <calculator.h>

namespace Calc::Math
{
    double factorial(double n)
    {
        if(n < 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }
} // namespace Calc
