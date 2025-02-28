#include "Polynomial.h"

Polynomial operator - (Polynomial poly)
{
    Polynomial result;
    result.n = poly.n;
    result.p = new Monomial[result.n];
    for (int i=0; i<result.n; i++)
        result.p[i] = -poly.p[i];

    return result;
}

void Polynomial::simplify()
{
    // Sắp xếp đa thức theo thứ tự giảm dần số mũ
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (p[i].getExponent() < p[j].getExponent())
            {
                Monomial temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

    //  Nếu các số mũ trùng nhau thì cộng rồi xoá
    for (int i=0; i<n-1; i++)
    {
        if (p[i].getExponent() == p[i+1].getExponent())
        {
            p[i].setCoefficient(p[i].getCoefficient() + p[i+1].getCoefficient());
            for (int j = i+1; j<n-1; j++)
            {
                p[j].setCoefficient(p[j+1].getCoefficient());
                p[j].setExponent(p[j+1].getExponent());
            }
            n--;
        }
    }
}

istream& operator >> (istream& is, Polynomial& polynomial)
{
    cout << "Nhap so don thuc trong da thuc: ";
    is >> polynomial.n;

    polynomial.p = new Monomial[polynomial.n];
    cout << "Nhap lan luot cac don thuc (he_so so_mu): ";
    for (int i=0; i<polynomial.n; i++)
        is >> polynomial.p[i];

    polynomial.simplify();

    cout << "===============================================\n\n";
    return is;
}

ostream& operator << (ostream& os, Polynomial polynomial)
{
    bool flag = 0;
    for (int i=0; i<polynomial.n; i++)
    {
        // Xuất hệ số
        if (polynomial.p[i].getCoefficient() == 0)
            continue;

        else if (polynomial.p[i].getCoefficient() == -1)
        {
            os << "-1";
            flag = 1;
        }
        else if (polynomial.p[i].getCoefficient() > 0)
        {
            if (flag == 1)
                os << "+";
            if (polynomial.p[i].getCoefficient() != 1 || polynomial.p[i].getExponent() == 0) os << polynomial.p[i].getCoefficient();
            flag = 1;
        }
        else
            {
                os << polynomial.p[i].getCoefficient();
                flag = 1;
            }

        // Xuất số mũ
        if (polynomial.p[i].getExponent() != 0)
            {
                if (polynomial.p[i].getExponent() != 1)
                    os << "x^" << polynomial.p[i].getExponent();
                else
                    os << "x";
                flag = 1;
            }
    }
    os << endl;

    return os;
}

Polynomial operator + (Polynomial poly1, Polynomial poly2)
{
    Polynomial result;
    result.n = poly1.n + poly2.n;
    result.p = new Monomial[result.n];

    int i = 0, idx1 = 0, idx2 = 0;
    while (idx1 < poly1.n || idx2 < poly2.n)
    {
        if ((idx1 < poly1.n && idx2 < poly2.n && poly1.p[idx1].getExponent() < poly2.p[i].getExponent()) || idx2 >= poly2.n)
            result.p[i++] = poly1.p[idx1++];
        else
            result.p[i++] = poly2.p[idx2++];
    }

    result.simplify();
    return result;
}

Polynomial operator - (Polynomial poly1, Polynomial poly2)
{
    return poly1 + (-poly2);
}


Polynomial operator * (Monomial monomial, Polynomial polynomial)
{
    Polynomial result;
    result.n = polynomial.n;
    result.p = new Monomial[result.n];

    for (int i=0; i<result.n; i++)
    {
        result.p[i].setCoefficient(monomial.getCoefficient()*polynomial.p[i].getCoefficient());
        result.p[i].setExponent(monomial.getExponent() + polynomial.p[i].getExponent());
    }
    return result;
}

Polynomial operator * (Polynomial poly1, Polynomial poly2)
{
    Polynomial result;
    result.n = poly1.n * poly2.n;
    result.p = new Monomial[result.n];

    for (int i=0; i<result.n; i++)
    {
        result.p[i].setCoefficient(0);
        result.p[i].setExponent(0);
    }

    for (int i=0; i<poly1.n; i++)
    {
        Polynomial temp = poly1.p[i]*poly2;
        result = result + temp;
    }

    return result;
}

long long Polynomial::calculateValueOfFunction(int x)
{
    int result = 0;
    for (int i=0; i<n; i++)
        result = result + p[i].getCoefficient()*pow(x, p[i].getExponent());

    return result;
}
