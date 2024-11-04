#include <exception.h>

namespace Calc
{
    CalcException::CalcException(const char *s)
    {
        w = new char[strlen(s)];
        strcpy(w, s);
    }
    const char* CalcException::what() const noexcept
    {
        return w;
    }
} // namespace Calc
