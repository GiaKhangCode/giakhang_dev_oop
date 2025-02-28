#include "Complex.h"

Complex::Complex(float real, float imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}
Complex::Complex(const Complex& another)
{
    this->real = another.real;
    this->imaginary = another.imaginary;
}
float Complex::getReal()
{
    return real;
}
float Complex::getImaginary()
{
    return imaginary;
}
void Complex::setReal(float real)
{
    this->real = real;
}
void Complex::setImaginary(float imaginary)
{
    this->imaginary = imaginary;
}
void Complex::setComplex(float real, float imaginary)
{
    setReal(real);
    setImaginary(imaginary);
}

istream& operator >> (istream& is, Complex &complex)
{
    cout << "Nhap phan thuc: ";
    is >> complex.real;

    cout << "Nhap phan ao: ";
    is >> complex.imaginary;

    return is;
}

ostream& operator << (ostream& os, Complex complex)
{
    if (complex.real != 0)
        os << complex.real;

    if (complex.imaginary < 0)
        os << complex.imaginary << "i";

    if (complex.imaginary > 0 && complex.real != 0)
        os << "+" << complex.imaginary << "i";

    else if (complex.imaginary > 0)
        os << complex.imaginary << "i";

    else if (complex.real == 0 && complex.imaginary == 0)
        os << 0;
    return os;
}


Complex operator + (Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;

    return result;
}

Complex operator - (Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;

    return result;
}
Complex operator * (Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real*c2.real - c1.imaginary*c2.imaginary;
    result.imaginary = c1.real*c2.imaginary + c1.imaginary*c2.real;

    return result;
}
Complex operator / (Complex c1, Complex c2)
{
    Complex result;
    result.real = (c1.real*c2.real + c1.imaginary*c2.imaginary) / (c2.real*c2.real + c2.imaginary*c2.imaginary);
    result.imaginary = (-c1.real*c2.imaginary + c1.imaginary*c2.real) / (c2.real*c2.real + c2.imaginary*c2.imaginary);

    return result;
}

bool operator == (Complex c1, Complex c2)
{
    return ((c1.real == c2.real) && (c1.imaginary == c2.imaginary));
}
bool operator != (Complex c1, Complex c2)
{
    return ((c1.real != c2.real) || (c1.imaginary != c2.imaginary));
}

Complex& Complex::operator = (Complex& anotherComplex)
{
    this->real = anotherComplex.real;
    this->imaginary = anotherComplex.imaginary;
}

float Complex::magnitude()
{
    return sqrt(this->real*this->real + this->imaginary*this->imaginary);
}

Complex Complex::conjugate()
{
    Complex result = *this;
    result.imaginary = -this->imaginary;

    return result;
}
Complex Complex::reciprocal()
{
    Complex one(1);
    return (one / *this);
}

bool Complex::isReal()
{
    return (this->imaginary == 0);
}
bool Complex::isImaginary()
{
    return (this->real == 0 && this->imaginary != 0);
}
