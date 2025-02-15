#include <iostream>
#include <cmath>

using namespace std;

int i = 1;

class CSoPhuc
{
    private:
        float a;
        float b;
    
    public:
        friend istream& operator >> (istream&, CSoPhuc&);
        friend ostream& operator << (ostream&, CSoPhuc);
        float mod();
        CSoPhuc operator + (CSoPhuc);
        CSoPhuc operator - (CSoPhuc);
        CSoPhuc operator * (CSoPhuc);
        CSoPhuc operator / (CSoPhuc);
};

int main()
{
    // Khai báo và nhập xuất số phức
    CSoPhuc x, y;
    cin >> x >> y;
    cout << "======================================\n\n";
    cout << "Ban vua nhap hai so phuc: " << x << " va " << y << endl;
    // Xuất module hai số phức
    cout << "Module so phuc thu nhat: " << x.mod() << endl;
    cout << "Module so phuc thu hai: " << y.mod() << endl;

    // Xuất tổng hai số phức
    cout << "Tong hai so phuc la: " << x + y << endl;

    //Xuất hiệu hai số phức
    CSoPhuc Sub = x - y;
    cout << "Hieu hai so phuc la: " << x - y << endl;

    //Xuất tích hai số phức
    cout << "Tich hai so phuc la: " << x * y << endl;

    // Xuất thương hai số phức
    cout << "Thuong hai so phuc la: " << x / y << endl;

    return 0;
}

istream& operator >> (istream &is, CSoPhuc &X)
{
    cout << "Nhap phan thuc cua so phuc thu " << i << ": "; 
    is >> X.a;

    cout << "Nhap phan ao cua so phuc thu " << i << ": ";
    is >> X.b;

    i++;
    return is;
}

ostream& operator << (ostream &os, CSoPhuc X)
{
    if (X.a != 0 )
        os << X.a;
    if (X.a == 0)
        os << X.b << "i";
    else if (X.b > 0)
        os << "+" << X.b << "i";
    else if (X.b < 0)
        os << X.b << "i";
    
    return os;
}

float CSoPhuc::mod()
{
    return sqrt(a*a + b*b);
}

CSoPhuc CSoPhuc::operator+(CSoPhuc another)
{
    CSoPhuc kq;
    kq.a = a + another.a;
    kq.b = b + another.b;
    
    return kq;
}


CSoPhuc CSoPhuc::operator - (CSoPhuc another)
{
    CSoPhuc kq;
    kq.a = a - another.a;
    kq.b = b - another.b;
    
    return kq;
}

CSoPhuc CSoPhuc::operator * (CSoPhuc another)
{
    CSoPhuc kq;
    kq.a = a*another.a - b*another.b;
    kq.b = a*another.b + b*another.a;

    return kq;
}

CSoPhuc CSoPhuc::operator / (CSoPhuc another)
{
    CSoPhuc kq;
    kq.a = (a*another.a + b*another.b) / (another.a*another.a + another.b*another.b);
    kq.b = (a*-another.b+b*another.a) / (another.a*another.a + another.b*another.b);

    return kq;
}
