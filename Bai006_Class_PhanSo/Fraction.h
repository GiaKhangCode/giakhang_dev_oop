#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator; // Tử số
    int denominator; // Mẫu số
public:
    Fraction(int numerator = 1, int denominator = 1);
    double getValue();
    void setValue(int numerator, int denominator);  // Phương thức thay đổi giá trị
    void display();                                 // Phương thức hiển thị
    void simplify();                                // Phương thức rút gọn
    Fraction reciprocal();                          // Phương thức nghịch đảo
    Fraction add(Fraction);                         // Phương thức cộng
    Fraction subtract(Fraction);                    // Phương thức trừ
    Fraction multifly(Fraction);                    // Phương thức nhân
    Fraction divide(Fraction);                      // Phương thức chia
    Fraction power(int exponent);                   // Phương thức luỹ thừa với số mũ nguyên
    bool compareEqual(Fraction);                    // Phương thức so sánh bằng
    bool compareLessThan(Fraction);                 // Phương thức so sánh nhỏ hơn
    bool compareLessThanOrEqual(Fraction);          // Phương thức so sánh nhỏ hơn hoặc bằng
    bool compareGreaterThan(Fraction);              // Phương thức so sánh lớn hơn
    bool compareGreaterThanOrEqual(Fraction);       // Phương thức so sánh lớn hơn hoặc bằng
};

#endif // FRACTION_H
