#include <calculator.h>

namespace Calc::Math
{
    double factorial(MainValType n)
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
