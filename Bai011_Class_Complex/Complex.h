#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
    private:
        float real;         // Phần thực
        float imaginary;    // Phần ảo
    public:
        Complex(float real = 0, float imaginary = 0);       // Phương thức thiết lập
        Complex(const Complex&);                            // Phương thức thiết lập sao chép
        friend istream& operator >> (istream&, Complex&);   // Nạp chồng toán tử nhập
        friend ostream& operator << (ostream&, Complex);    // Nạp chồng toán tử xuất
        float getReal();                                    // Lấy giá trị của phần thực
        float getImaginary();                               // Lấy giá trị của phần ảo
        void setReal(float real);                           // Thay đổi giá trị phần thực
        void setImaginary(float imaginary);                 // Thay đổi giá trị phần ảo
        void setComplex(float real, float imaginary);       // Thay đổi giá trị số phức
        friend Complex operator + (Complex, Complex);       // Nạp chồng toán tử +
        friend Complex operator - (Complex, Complex);       // Nạp chồng toán tử -
        friend Complex operator * (Complex, Complex);       // Nạp chồng toán tử *
        friend Complex operator / (Complex, Complex);       // Nạp chồng toán tử /
        friend bool operator == (Complex, Complex);         // Nạp chồng toán tử ==
        friend bool operator != (Complex, Complex);         // Nạp chồng toán tử !=
        Complex& operator = (Complex&);                     // Phép gán số phức
        float magnitude();                                  // Tính module số phức
        Complex conjugate();                                // Số phức liên hợp
        Complex reciprocal();                               // Số phức nghịch đảo
        bool isReal();                                      // Kiểm tra số thức là số thực
        bool isImaginary();                                 // Kiểm tra số phức là số thuần ảo
};

#endif // COMPLEX_H
