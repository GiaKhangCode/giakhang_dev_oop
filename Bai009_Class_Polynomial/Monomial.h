#ifndef MONOMIAL_H
#define MONOMIAL_H
#include <iostream>

using namespace std;

class Monomial
{
    private:
        int coefficient;     // hệ số
        int exponent;       // số mũ
    public:
        friend istream& operator >> (istream&, Monomial&);  // Nạp chồng toán tử nhập
        friend ostream& operator << (ostream&, Monomial);   // Nạp chồng toán tử xuất
        int getCoefficient();                               // Lấy giá trị hệ số
        int getExponent();                                  // Lấy giá trị số mũ
        void setCoefficient(int coefficient);               // Thay đổi giá trị hệ số
        void setExponent(int exponent);                     // Thay đổi giá trị số mũ
        friend Monomial operator - (Monomial const);        // Trả về đơn thức đối
};

#endif // MONOMIAL_H
