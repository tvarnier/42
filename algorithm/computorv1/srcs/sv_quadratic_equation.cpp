#include "computorv1.hpp"

static int  sv_quadratic_negative(Equation eq, char element, double a, double b, double delta)
{
    printendl("Discriminant is strictly negative, the solutions are:");
        
    print(" ", eq.getVariable(), "₁ = ");
    if (eq.getVerbose())
    {
        print(GREY, "(-", char(element + 1), " - i√-Δ) / 2", element, " = ");
        print(GREY, "(", -b, " - i√", -delta,") / 2 * ", a, " = ");
    }
    sv_division((-b), 2.0 * a, true);
    print(" - ");
    sv_division(lib::sqrt(-delta), 2.0 * a, true);
    print("i\n");

    print(" ", eq.getVariable(), "₂ = ");
    if (eq.getVerbose())
    {
        print(GREY, "(-", char(element + 1), " + i√-Δ) / 2", element, " = ");
        print(GREY, "(", -b, " + i√", -delta,") / 2 * ", a, " = ");
    }
    sv_division((-b), 2.0 * a, true);
    print(" + ");
    sv_division(lib::sqrt(-delta), 2.0 * a, true);
    print("i\n");
    return (0);
}


static int  sv_quadratic_null(Equation eq, char element, double a, double b)
{
    printendl("Discriminant is equal to zero, the solution is:");
    if (eq.getVerbose())
    {
        printendl(GREY, " ", eq.getVariable(), " = -", char(element + 1), " / 2", element);
        printendl(GREY, " ", eq.getVariable(), " = ", -b, " / 2 * ", a);
    }
    print(" ", eq.getVariable(), " = ");
    sv_division(-b, 2 * a, false);
    print("\n");
    return (0);
}


static int  sv_quadratic_positive(Equation eq, char element, double a, double b, double delta)
{
    printendl("Discriminant is strictly positive, the solutions are:");
    
    print(" ", eq.getVariable(), "₁ = ");
    if (eq.getVerbose())
    {
        print(GREY, "(-", char(element + 1), " - √Δ) / 2", element, " = ");
        print(GREY, "(", -b, " - √", delta,") / 2 * ", a, " = ");
    }
    sv_division((-b - lib::sqrt(delta)), 2.0 * a, false);
    print("\n");

    print(" ", eq.getVariable(), "₂ = ");
    if (eq.getVerbose())
    {
        print(GREY, "(-", char(element + 1), " + √Δ) / 2", element, " = ");
        print(GREY, "(", -b, " + √", delta,") / 2 * ", a, " = ");
    }
    sv_division((-b + lib::sqrt(delta)), 2.0 * a, false);
    print("\n");
    return (0);
}

int     sv_quadratic_equation(Equation eq)
{
    string  element_str("abcABC");
    char    element((element_str.find(eq.getVariable()) != string::npos) ? 'x' : 'a');
    double  a(eq.getValueFromExponent(2));
    double  b(eq.getValueFromExponent(1));
    double  c(eq.getValueFromExponent(0));
    double  delta(0);

    if (eq.getVerbose())
        printendl(GREY, " ", element, eq.getVariable(), "² + ", char(element + 1), eq.getVariable(), " + ", char(element + 2), " = 0");

    // DELTA

    delta = lib::pow(b, 2) - (4.0 * a * c);
    if (eq.getVerbose())
    {
        printendl(GREY, " Δ = ", char(element + 1), "² - 4", element, char(element + 2));
        printendl(GREY, " Δ = ", b, "² - 4 * ", a, " * ", c);
        printendl(GREY, " Δ = ", delta);
    }

    // SOLUTIONS

    if (delta < 0)
        return (sv_quadratic_negative(eq, element, a, b, delta));
    else if (delta == 0)
        return (sv_quadratic_null(eq, element, a, b));
    else if (delta > 0)
        return (sv_quadratic_positive(eq, element, a, b, delta));
    return (0);
}