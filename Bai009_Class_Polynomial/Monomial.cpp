#include "Monomial.h"

istream& operator >> (istream& is, Monomial& monomial)
{
    is >> monomial.coefficient >> monomial.exponent;
}

ostream& operator << (ostream& os, Monomial monomial)
{
    // Xuất hệ số
    if (monomial.getCoefficient() == 0)
            return os;

    else if (monomial.getCoefficient() == -1)
            os << "-1";
    else if (monomial.getCoefficient() > 0)
    {
        if (monomial.getCoefficient() != 1 || monomial.getExponent() == 0)
                os << monomial.getCoefficient();
    }
    else
        os << monomial.getCoefficient();

    // Xuất số mũ
    if (monomial.getExponent() != 0)
        if (monomial.getExponent() != 1)
            os << "x^" << monomial.getExponent();
        else
            os << "x";

    return os;
}

Monomial operator - (Monomial monomial)
{
    Monomial result;
    result.coefficient = -monomial.coefficient;
    result.exponent = monomial.exponent;

    return result;
}
int Monomial::getCoefficient()
{
    return coefficient;
}
int Monomial::getExponent()
{
    return exponent;
}
void Monomial::setCoefficient(int coefficient)
{
    this->coefficient = coefficient;
}
void Monomial::setExponent(int exponent)
{
    this->exponent = exponent;
}
