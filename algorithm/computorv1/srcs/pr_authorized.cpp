#include "computorv1.hpp"

Element     pr_get_element(string const& s, int& i, char const var)
{
    if (!s[i])
        return (None);
    else if (s[i] == '+' || s[i] == '-')
        return (Sign);
    else if (isdigit(s[i]))
        return (Number);
    else if (s[i] == '*')
        return (Multiply);
    else if (s[i] == var)
        return (Variable);
    else if (s[i] == '^' && s[i + 1] && isdigit(s[i + 1]))
        return (Exponent);
    else if (s[i] == '^')
    {
        printerr(RED, "ERROR: '^' Must preceed a Natural Number.");
        return (Error);
    }
    else
    {
        printerr(RED, "ERROR: Unexpected character: '", s[i], "'.");
        return (Error);
    }
}

int         pr_authorized(Element& last, Element& el)
{
    if ((last == None && (el == Sign || el == Number || el == Variable))
            || (last == Sign && (el == Number || el == Variable))
            || (last == Number && (el == Multiply || el == Variable || el == Sign || el == None))
            || (last == Multiply && (el == Variable))
            || (last == Variable && (el == Exponent || el == Sign || el == None))
            || (last == Exponent && (el == Sign || el == None)))
        return (0);
    else if (last == None)
    {
        if (el == Multiply)
            return (pr_error("'*' Must follow a Number and preceed a Variable."));
        else if (el == Exponent)
            return (pr_error("Exponent must follow a variable."));
        else if (el == None)
            return (pr_error("Empty expression."));
    }
    else if (last == Sign)
    {
        if (el == Sign)
            return (pr_error("Sign must preceed a Number or a Variable."));
        else if (el == Multiply)
            return (pr_error("'*' Must follow a Number and preceed a Variable."));
        else if (el == Exponent)
            return (pr_error("Exponent must follow a Variable."));
        else if (el == None)
            return (pr_error("Sign must preceed a Number or a Variable."));
    }
    else if (last == Number)
    {
        if (el == Number)
            return (pr_error("A Number can't follow an other one."));
        else if (el == Multiply)
            return (pr_error("'*' Must follow a Number and preceed a Variable."));
        else if (el == Exponent)
            return (pr_error("Exponent must follow a Variable."));
    }
    else if (last == Multiply)
        return (pr_error("'*' Must follow a Number and preceed a Variable."));
    else if (last == Variable)
    {
        if (el == Number)
            return (pr_error("A Number can't follow a Variable."));
        else if (el == Multiply)
            return (pr_error("'*' Must follow a Number and preceed a Variable."));
        else if (el == Variable)
            return (pr_error("A Variable can't follow an other one."));
    }
    else if (last == Exponent)
    {
        if (el == Number)
            return (pr_error("A Number can't follow an Exponent."));
        else if (el == Multiply)
            return (pr_error("'*' Must follow a Number and preceed a Variable."));
        else if (el == Variable)
            return (pr_error("A Variable can't follow an Exponent."));
        else if (el == Exponent)
            return (pr_error("An Exponent can't follow an other one."));
    }
    return (1);
}