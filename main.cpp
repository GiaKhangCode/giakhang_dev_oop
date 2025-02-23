#include "Fraction.h"

using namespace std;

int main()
{
    Fraction A(10, 2);
    cout << "A = "; A.display();

    A.simplify();
    cout << "\nAfter simplify: A = "; A.display();
    cout << "\nReciprocation of A = "; A.reciprocal().display();

    A.setValue(1,2);
    cout << "\nA after set value: "; A.display();

    Fraction B(1,3);
    cout << "\nB = "; B.display();

    cout << "\nA + B = "; A.display(); cout << " + "; B.display(); cout << " = "; A.add(B).display();

    cout << "\nA - B = "; A.display(); cout << " - "; B.display(); cout << " = "; A.subtract(B).display();

    cout << "\nA x B = "; A.display(); cout << " x "; B.display(); cout << " = "; A.multifly(B).display();

    cout << "\nA : B = "; A.display(); cout << " : "; B.display(); cout << " = "; A.divide(B).display();

    cout << "\nA^3 = ("; A.display(); cout << "^3) = "; A.power(3).display();

    cout << "\nA == B ? Answer: " << A.compareEqual(B);
    cout << "\nA < B ? Answer: " << A.compareLessThan(B);
    cout << "\nA <= B ? Answer: " << A.compareLessThanOrEqual(B);
    cout << "\nA > B ? Answer: " << A.compareGreaterThan(B);
    cout << "\nA >= B ? Answer: " << A.compareGreaterThanOrEqual(B);
    return 0;
}
