#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <cmath>
#include "Monomial.h"

using namespace std;

class Polynomial
{
    private:
        int n;          // số đơn thức trong đa thức
        Monomial *p;     // mảng các đơn thức
    public:
        friend istream& operator >> (istream&, Polynomial&);          // Nạp chồng toán tử nhập
        friend ostream& operator << (ostream&, Polynomial);           // Nạp chồng toán tử xuất
        void simplify();                                              // Rút gọn đa thức
        friend Polynomial operator + (Polynomial, Polynomial);        // Nạp chồng toán tử +
        friend Polynomial operator - (Polynomial);                    // Trả về đa thức đối
        friend Polynomial operator - (Polynomial, Polynomial);        // Nạp chồng toán tử -
        friend Polynomial operator * (Monomial, Polynomial);          // Nạp chồng toán tử *
        friend Polynomial operator * (Polynomial, Polynomial);        // Nạp chồng toán tử *
        long long calculateValueOfFunction(int x);
};

#endif // POLYNOMIAL_H
