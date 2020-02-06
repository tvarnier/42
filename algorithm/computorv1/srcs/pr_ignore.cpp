#include "computorv1.hpp"

void    pr_ignore_space(string const& s, int& i, bool& space)
{
    space = (s[i] == ' ') ? true : false;
    while (s[i] == ' ')
        ++i;
}

void    pr_ignore_number(string const& s, int& i)
{
    if (s[i] == '+' || s[i] == '-')
        ++i;
    while (isdigit(s[i]))
        ++i;
    if (s[i] && s[i] == '.' && s[i + 1] && isdigit(s[i + 1]))
    {
        ++i;
        while (isdigit(s[i]))
            i++;
    }
}

void    pr_ignore_exponent(string const& s, int& i)
{
    ++i;
    while (isdigit(s[i]))
        ++i;
}