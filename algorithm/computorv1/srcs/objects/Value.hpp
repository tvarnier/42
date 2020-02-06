#ifndef VALUE_HPP
# define VALUE_HPP

# include "computorv1.hpp"

class   Value
{
    public :
        Value(double value, int exponent);
        Value(Value const& other);

        double  getValue() const;
        void    setValue(const double value);
        void    inverse();

        int     getExponent() const;
        void    setExponent(const int exponent);

        Value&  operator=(Value const& a);
        Value&  operator+=(Value const& a);
        Value&  operator-=(Value const& a);

    private :
        double  m_value;
        int     m_exp;
};

bool    operator<(Value const& a, Value const& b);

Value   operator+(Value const& a, Value const& b);
Value   operator-(Value const& a, Value const& b);

# endif