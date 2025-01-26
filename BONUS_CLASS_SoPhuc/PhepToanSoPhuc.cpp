#include <iostream>

using namespace std;

class CSoPhuc
{
    private:
        float a;
        float b;
    
    public:
        friend istream& operator >> (istream&, CSoPhuc&);
        friend ostream& operator << (ostream&, CSoPhuc);
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
    cout << "Ban vua nhap hai so phuc: " << x << " va " << y << endl;

    // Xuất tổng hai số phức
    CSoPhuc Add = x + y;
    cout << "Tong hai so phuc la: " << Add << endl;

    //Xuất hiệu hai số phức
    CSoPhuc Sub = x - y;
    cout << "Hieu hai so phuc la: " << Sub << endl;

    //Xuất tích hai số phức
    CSoPhuc Multi = x * y;
    cout << "Tich hai so phuc la: " << Multi << endl;

    // Xuất thương hai số phức
    CSoPhuc Div = x/y;
    cout << "Thuong hai so phuc la: " << Div << endl;

    return 0;
}

istream& operator >> (istream &is, CSoPhuc &X)
{
    cout << "Nhap phan thuc: ";
    is >> X.a;

    cout << "Nhap phan ao: ";
    is >> X.b;

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