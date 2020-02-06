#ifndef EQUATION_HPP
# define EQUATION_HPP

# include "computorv1.hpp"

class   Equation
{
    public :
        Equation();

        void        print() const;
        void        simplify();
        void        order();

        char        getVariable() const;
        void        setVariable(const char variable);

        list<Value> getLeft() const;
        void        setLeft(const list<Value> left);
        void        printLeft() const;

        list<Value> getRight() const;
        void        setRight(const list<Value> right);
        void        printRight() const;

        int         getMinExponent() const;
        int         getMaxExponent() const;

        double      getValueFromExponent(int exponent) const;

        bool        getVerbose() const;
        void        setVerbose(const bool verbose);

        bool        empty() const;

    private :
        bool        m_verbose;
        char        m_variable;
        int         m_min_exp;
        int         m_max_exp;
        list<Value> m_left;
        list<Value> m_right;

        void    printExpression(list<Value> const& expr) const;
        void    eraseNull(list<Value>& expr);

        void    hasChanged();
        void    setMinExponent();
        void    setMaxExponent();
};

#endif