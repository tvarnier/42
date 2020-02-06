#include "Value.hpp"

Value::Value(double value, int exponent) : m_value(value), m_exp(exponent)
{}
Value::Value(Value const& other) : m_value(other.getValue()), m_exp(other.getExponent())
{}

//  ENCAPSULATION

double  Value::getValue() const { return (m_value); }
void    Value::setValue(const double value) { m_value = value; }
void    Value::inverse() { m_value *= -1; }

int     Value::getExponent() const { return (m_exp); }
void    Value::setExponent(const int exponent) { m_exp = exponent; }

// OPERATOR OVERLOADING

Value&  Value::operator=(Value const& a)
{
    m_value = a.getValue();
    m_exp = a.getExponent();
    return (*this);
}

Value&  Value::operator+=(Value const& a)
{
    if (m_exp != a.getExponent())
        throw domain_error("Exponents are different");
    m_value += a.getValue();

    return (*this);
}

Value&  Value::operator-=(Value const& a)
{
    if (m_exp != a.getExponent())
        throw domain_error("Exponents are different");
    m_value -= a.getValue();

    return (*this);
}

bool    operator<(Value const& a, Value const& b)
{
    if (a.getExponent() == b.getExponent())
    {
        if (a.getValue() < b.getValue())
            return (true);
        return (false);
    }
    else if (a.getExponent() < b.getExponent())
        return (true);
    return (false);
}

Value   operator+(Value const& a, Value const& b)
{
    if (a.getExponent() != b.getExponent())
        throw domain_error("Exponents are different");

    Value res(a.getValue() + b.getValue(), a.getExponent());
    return (res);
}

Value   operator-(Value const& a, Value const& b)
{
    if (a.getExponent() != b.getExponent())
        throw domain_error("Exponents are different");

    Value res(a.getValue() - b.getValue(), a.getExponent());
    return (res);
}


