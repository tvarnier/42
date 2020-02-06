#include "Equation.hpp"

Equation::Equation() : m_verbose(false), m_variable(0), m_min_exp(0), m_max_exp(0)
{}

void    Equation::print() const
{
    printLeft();
    cout << " = ";
    printRight();
    cout << endl;
}

void    Equation::simplify()
{
    list<Value>::iterator it;
    list<Value>::iterator it2;

    for(it = m_right.begin(); it != m_right.end(); ++it)
        it->inverse();
    m_left.insert(m_left.end(), m_right.begin(), m_right.end());
    m_right.clear();

    eraseNull(m_left);

    it = m_left.begin();
    while (it != m_left.end())
    {
        it2 = next(it);
        while (it2 != m_left.end())
            if (it->getExponent() == it2->getExponent())
            {
                *it += *it2;
                it2 = m_left.erase(it2);
            }
            else
                ++it2;    
        ++it;
    }

    eraseNull(m_left);

    Equation::hasChanged();
}

void    Equation::order() { m_left.sort(); m_left.reverse(); m_right.reverse(); m_right.sort(); }

//  ENCAPSULATION

char    Equation::getVariable() const { return (m_variable); }
void    Equation::setVariable(const char variable) { m_variable = variable; }

list<Value>     Equation::getLeft() const { return (m_left); }
void            Equation::setLeft(const list<Value> left) { m_left = left; Equation::hasChanged(); }
void            Equation::printLeft() const { printExpression(m_left); }

list<Value>     Equation::getRight() const { return (m_right); }
void            Equation::setRight(const list<Value> right) { m_right = right; Equation::hasChanged(); }
void            Equation::printRight() const { printExpression(m_right); }

int             Equation::getMinExponent() const { return (m_min_exp); }
int             Equation::getMaxExponent() const { return (m_max_exp); }

double          Equation::getValueFromExponent(int exponent) const
{
    list<Value>::const_iterator it;

    for(it = m_left.begin(); it != m_left.end(); ++it)
        if (it->getExponent() == exponent)
            return (it->getValue());
    return (0);
}

bool            Equation::getVerbose() const { return (m_verbose); }
void            Equation::setVerbose(const bool verbose) { m_verbose = verbose; }

bool            Equation::empty() const { return (m_left.empty() && m_right.empty()); }

// PRIVATE FUNCTIONS

void    Equation::printExpression(list<Value> const& expr) const
{
    list<Value>::const_iterator it;
    int     count(0);

    for(it = expr.begin(); it != expr.end(); ++it) 
    {
        if (it->getValue())
        {
            if (count)
                cout << " ";
            if (it->getValue() < 0)
                cout << "-";
            else if (count)
                cout << '+';
            if (count)
                cout << ' ';
            if (abs(it->getValue()) != 1 || it->getExponent() == 0)
                cout << abs(it->getValue());
            if (it->getExponent())
            {
                cout << m_variable;
                if (it->getExponent() > 1)
                    cout << "^" << it->getExponent();
            }
            ++count;
        }
    }
    if (count == 0)
        cout << "0";
}

void    Equation::eraseNull(list<Value>& expr)
{
    list<Value>::iterator it;

    it = expr.begin();
    while (it != expr.end())
    {
        if (!it->getValue())
            it = expr.erase(it);
        else
            ++it;
    }
    Equation::hasChanged();
}

// HAS CHANGED

void    Equation::hasChanged()
{
    Equation::setMinExponent();
    Equation::setMaxExponent();
}
void    Equation::setMinExponent()
{
    list<Value>::iterator it;

    m_min_exp = 0;
    if (Equation::empty())
        return ;
    else
    {
        for (it = m_left.begin(); it != m_left.end(); ++it)
            if (it->getExponent() < m_min_exp)
                m_min_exp = it ->getExponent();
        for (it = m_right.begin(); it != m_right.end(); ++it)
            if (it->getExponent() < m_min_exp)
                m_min_exp = it ->getExponent(); 
    }
}
void    Equation::setMaxExponent()
{
    list<Value>::iterator it;

    m_max_exp = 0;
    if (Equation::empty())
        return ;
    else
    {
        for (it = m_left.begin(); it != m_left.end(); ++it)
            if (it->getExponent() > m_max_exp)
                m_max_exp = it ->getExponent();
        for (it = m_right.begin(); it != m_right.end(); ++it)
            if (it->getExponent() > m_max_exp)
                m_max_exp = it ->getExponent(); 
    }
}