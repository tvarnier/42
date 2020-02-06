#include "computorv1.hpp"

static int      check_variable(Equation& eq, char const *s)
{
    int     i(-1);
    int     c(0);

    while (s[++i])
        if (isalpha(s[i]))
        {
            if (c == 0)
                c = s[i];
            else if (c != s[i])
                return (1);
        }
    if (c == 0)
        return (1);
    eq.setVariable(c);
    return (0);
}

int             pr_basic_checks(Equation& eq, char const *s)
{
    if (lib::count_char(s, '=') != 1)
        return (pr_error("An equation is composed of ONE equal."));
    else if (check_variable(eq, s))
        return (pr_error("ERROR: The equation must have ONE variable. (One alphabetic character)"));
    return (0);
}