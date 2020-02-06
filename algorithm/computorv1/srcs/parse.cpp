#include "computorv1.hpp"

static int  pr_expression(list<Value>& expr, string const& s, char const var)
{
    int     i(0);
    bool    space(false);
    Element last(None);
    Element el(None);
    int     sign(1);
    Value   val(0, 0);

    while (s[i])
    {
        pr_ignore_space(s, i, space);
        last = el;
        if ((el = pr_get_element(s, i, var)) == Error)
            return (1);
        if (pr_authorized(last, el))
            return (1);
        switch (el)
        {
            case Sign:
                if (last != None)
                {
                    expr.push_back(val);
                    val.setValue(0);
                    val.setExponent(0);
                }
                sign = (s[i] == '-') ? -1 : 1;
                ++i;
                break;
            case Number:
                val.setValue(sign * atof(s.c_str() + i));
                pr_ignore_number(s, i);
                break;
            case Multiply:
                ++i;
                break;
            case Variable:
                if (space && last == Number)
                    return (pr_error("No spaces between a Number and a variable."));
                ++i;
                val.setExponent(1);
                if (last != Number && last != Multiply)
                    val.setValue(double(sign));
                break;
            case Exponent:
                if (space)
                    return (pr_error("No spaces before the exponent."));
                val.setExponent(atoi(s.c_str() + i + 1));
                pr_ignore_exponent(s, i);
                break;
            default:
                break;
        }
    }
    expr.push_back(val);
    return (0);
}

int                 parse(Equation& eq, char *s)
{
    string str(s);
    list<Value> left;
    list<Value> right;

    if (pr_basic_checks(eq, s))
        return (1);

    if (pr_expression(left, str.substr(0, str.find("=")), eq.getVariable()))
        return (1);
    eq.setLeft(left);

    if (pr_expression(right, str.substr(str.find("=") + 1), eq.getVariable()))
        return (1);
    eq.setRight(right);
    
    return (0);
}