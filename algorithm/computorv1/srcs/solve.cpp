#include "computorv1.hpp"

int             solve(Equation eq)
{
    if (sv_error(eq))
        return (1);
    if (eq.empty())
        printendl("All real numbers are solution");
    else if (eq.getMaxExponent() == 1)
        sv_simple_equation(eq);
    else if (eq.getMaxExponent() == 2)
        sv_quadratic_equation(eq);
    return (0);
}