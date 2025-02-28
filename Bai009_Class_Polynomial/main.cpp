#include "Polynomial.h"
#include "Monomial.h"
using namespace std;

int main()
{
    Polynomial F, G;
    cout << "NHAP DA THUC THU NHAT F(x)\n";
    cin >> F;
    cout << "NHAP DA THUC THU HAI G(x)\n";
    cin >> G;
    cout << "F(x) = " << F << endl
        << "G(x) = " << G << endl
        << "F(x) + G(x) = " << F+G << endl
        << "F(x) - G(x) = " << F-G << endl
        << "F(x) * G(x) = " << F*G << endl;
    int x;
    cout << "NHAP VAO x DE TINH F(x) VA G(x): ";
    cin >> x;
    cout << "F(" << x << ") = " << F.calculateValueOfFunction(x) << endl
        << "G(" << x << ") = " << G.calculateValueOfFunction(x);
}
