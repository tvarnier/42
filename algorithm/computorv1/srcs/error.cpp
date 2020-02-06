#include "computorv1.hpp"

int     pr_error(char const *error)
{
    printerr(RED, "ERROR: ", error);
    return (1);
}

int     sv_error(Equation eq)
{
    printendl("Polynomial degree: ", eq.getMaxExponent());
    if (eq.empty())
        return (0);
    else if (eq.getMaxExponent() > 2)
    {
        printerr(RED, "The polynomial degree is stricly greater than 2, I can't solve.");
        return (1);
    }
    else if (eq.getMaxExponent() < 1)
    {
        printerr(RED, "The polynomial degree is stricly smaller than 1, I can't solve.");
        return (1);
    }
    else if (eq.getMinExponent() < 0)
    {
        printerr(RED, "A degree is smaller than 0, I can't solve.");
        return (1);
    }
    return (0);
}