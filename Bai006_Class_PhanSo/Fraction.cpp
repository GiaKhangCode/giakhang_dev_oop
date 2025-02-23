#include "Fraction.h"

int gcd(int a, int b)
{
    return (b==0) ? a : gcd(b, a%b);
}

Fraction::Fraction(int numerator, int denomirator)
{
    this->numerator = numerator;
    this->denominator = denomirator;
}

double Fraction::getValue()
{
    return (double(numerator)/denominator);
}

void Fraction::setValue(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::display()
{
    cout << this->numerator << "/" << this->denominator;
}

void Fraction::simplify()
{
    int greatestCommonDivisor = gcd(numerator, denominator);
    this->numerator /= greatestCommonDivisor;
    this->denominator /= greatestCommonDivisor;

    if (this->denominator < 0)
    {
        this->numerator = -(this->numerator);
        this->denominator = -(this->denominator);
    }
}

Fraction Fraction::reciprocal()
{
    Fraction reciprocalFraction;
    reciprocalFraction.numerator = this->denominator;
    reciprocalFraction.denominator = this->numerator;

    return reciprocalFraction;
}
Fraction Fraction::add(Fraction anotherFraction)
{
    Fraction result;
    result.numerator = this->numerator*anotherFraction.denominator + this->denominator*anotherFraction.numerator;
    result.denominator = this->denominator*anotherFraction.denominator;

    result.simplify();
    return result;
}
Fraction Fraction::subtract(Fraction anotherFraction)
{
    Fraction result;
    result.numerator = this->numerator*anotherFraction.denominator - this->denominator*anotherFraction.numerator;
    result.denominator = this->denominator*anotherFraction.denominator;

    result.simplify();
    return result;
}

Fraction Fraction::multifly(Fraction anotherFraction)
{
    Fraction result;
    result.numerator = this->numerator * anotherFraction.numerator;
    result.denominator = this->denominator * anotherFraction.denominator;

    result.simplify();
    return result;
}
Fraction Fraction::divide(Fraction anotherFraction)
{
    Fraction result;
    result.numerator = this->numerator*anotherFraction.denominator;
    result.denominator = this->denominator*anotherFraction.numerator;

    result.simplify();
    return result;
}
Fraction Fraction::power(int exponent)
{
    Fraction result;
    result.numerator = pow(this->numerator, exponent);
    result.denominator = pow(this->denominator, exponent);

    result.simplify();
    return result;
}

bool Fraction::compareEqual(Fraction anotherFraction)
{
    return (this->getValue() == anotherFraction.getValue());
}
bool Fraction::compareLessThan(Fraction anotherFraction)
{
    return (this->getValue() < anotherFraction.getValue());
}
bool Fraction::compareLessThanOrEqual(Fraction anotherFraction)
{
    return (this->getValue() <= anotherFraction.getValue());
}
bool Fraction::compareGreaterThan(Fraction anotherFraction)
{
    return (this->getValue() > anotherFraction.getValue());
}
bool Fraction::compareGreaterThanOrEqual(Fraction anotherFraction)
{
    return (this->getValue() >= anotherFraction.getValue());
}


