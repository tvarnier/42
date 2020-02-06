#ifndef COMPUTERVONE_HPP
# define COMPUTERVONE_HPP

# include "../lib/includes/lib.hpp"

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include <list> 
# include <iterator>
# include <limits>
# include <cstring>

using namespace std;
using namespace lib;

# include "../srcs/objects/Value.hpp"
class Value;
# include "../srcs/objects/Equation.hpp"
class Equation;

enum Element {
    None,
    Sign,
    Number,
    Multiply,
    Variable,
    Exponent,
    Error
};

// PARSER

int     parse(Equation& eq, char *s);
int     pr_basic_checks(Equation& eq, char const *s);

void    pr_ignore_space(string const& s, int& i, bool& space);
void    pr_ignore_number(string const& s, int& i);
void    pr_ignore_exponent(string const& s, int& i);

Element pr_get_element(string const& s, int& i, char const var);
int     pr_authorized(Element& last, Element& el);

// SOLVER

int     solve(Equation eq);

int     sv_simple_equation(Equation eq);
int     sv_quadratic_equation(Equation eq);

int     sv_division(double a, double b, bool parentheses);

// ERROR

int     pr_error(char const *error);
int     sv_error(Equation eq);

#endif