#include "computorv1.hpp"

int     sv_simple_equation(Equation eq)
{
    string  element_str("abAB");
    char    element((element_str.find(eq.getVariable()) != string::npos) ? 'x' : 'a');
    double  a(eq.getValueFromExponent(1));
    double  b(eq.getValueFromExponent(0));

    printendl("The Solution is:");
    if (eq.getVerbose())
    {
        printendl(GREY, " ", element, eq.getVariable(), " + ", char(element + 1), " = 0");
        printendl(GREY, " ", eq.getVariable(), " = ", char(element + 1), " / ", element);
        printendl(GREY, " ", eq.getVariable(), " = ", -b, " / ", a);
    }
    print(" ", eq.getVariable(), " = ");
    sv_division(-b, a, false);
    print("\n");
    return (0);
}