#include "computorv1.hpp"

int     sv_division(double a, double b, bool parentheses)
{
    double  pgcd(0);

    if (lib::fabs(a) == 0.0)
        print(0);
    else
    {
        if ((lib::fabs(a / b) / 0.001) - lib::floor(lib::fabs(a / b) / 0.001) < 0.0001)
            print(a/b);
        else
        {
            if (a < 0.0 && b < 0.0)
            {
                a = lib::fabs(a);
                b = lib::fabs(b);
            }
            pgcd = lib::pgcd(lib::fabs(a), lib::fabs(b));
            if ((lib::fabs(a / pgcd) / 0.001) - lib::floor(lib::fabs(a / pgcd) / 0.001) < 0.0001
                && (lib::fabs(b / pgcd) / 0.001) - lib::floor(lib::fabs(b / pgcd) / 0.001) < 0.0001)
            {
                a /= pgcd;
                b /= pgcd;
            }
            if (parentheses)
                print("(", a, " / ", b, ")");
            else
                print(a, " / ", b);
        }
    }
    return (0);
}