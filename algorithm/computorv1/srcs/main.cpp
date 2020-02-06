#include "computorv1.hpp"

int     main(int ac, char **av)
{
    Equation eq;
    list<Value> lst;

    if ((ac == 2 && strcmp(av[1], "-v")) || (ac == 3 && (!strcmp(av[1], "-v") || !strcmp(av[2], "-v")) && !(!strcmp(av[1], "-v") && !strcmp(av[2], "-v"))))
    {
        if (ac == 3)
            eq.setVerbose(true);
        if (parse(eq, (ac == 3 && !strcmp(av[1], "-v")) ? av[2] : av[1]))
            return (1);
        eq.simplify();
        eq.order();
        print("Reduced form: ");
        eq.print();
        solve(eq);
    }
    else
        printendl("Usage: ./computor [-v] <equation>");
    return (0);
}