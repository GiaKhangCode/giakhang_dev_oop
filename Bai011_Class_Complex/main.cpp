#include "Complex.h"

int main()
{
    Complex c1;
    Complex c2(3);
    Complex c3(0,4);
    Complex c4(5,6);

    cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << "\nc4 = " << c4;

    cout << "\n\n|c1| = " << c1.magnitude() << "\n|c2| = " << c2.magnitude()
        << "\n|c3| = " << c3.magnitude() << "\n|c4| = " << c4.magnitude();

    cout << "\n\nc2 + c3 = " << c2 + c3 << "\t\tc3 + c4 = " << c3 + c4;
    cout << "\nc2 - c3 = " << c2 - c3 << "\t\tc3 - c4 = " << c3 - c4;
    cout << "\nc2 x c3 = " << c2 * c3 << "\t\tc3 x c4 = " << c3 * c4;
    cout << "\nc2 : c3 = " << c2 / c3 << "\tc3 : c4 = " << c3 / c4;

    if (c1.isReal())
        cout << "\n\nc1 la so thuc";
    else
        cout << "\n\nc1 khong la so thuc";

    if (c2.isImaginary())
        cout << "\nc2 la so thuan ao";
    else
        cout << "\nc2 khong la so thuan ao";

    if (c3.isImaginary())
        cout << "\nc3 la so thuan ao";
    else
        cout << "\nc3 khong la so thuan ao";

    Complex c5;
    c5.setComplex(0,4);

    cout << "\n\nc5 = " << c5;
    if (c3 == c5)
        cout << "\nc3 bang c5";
    else
        cout << "\nc3 khac c5";

    cout << "\n\nSo phuc lien hop cua c4: " << c4.conjugate()
        << "\nSo phuc nghich dao cua c4: " << c4.reciprocal();

    return 0;
}
