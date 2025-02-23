#include "Point.h"

int main()
{
    Point A(3,4);
    cout << "A"; A.display();
    cout << "\nDiem doi xung qua OX cua A: "; A.reflectOX().display();
    cout << "\nDiem doi xung qua OY cua A: "; A.reflectOY().display();

    Point B(5,12);
    cout << "\n\nB"; B.display();
    cout << "\nDiem doi xung qua OX cua B: "; B.reflectOX().display();
    cout << "\nDiem doi xung qua OY cua B: "; B.reflectOY().display();

    if (A.isOverlap(B))
        cout << "\nA va B trung nhau";
    else
        cout << "\nA va B khong trung nhau";

    cout << "\n\nOA = " << A.distanceToOrigin();
    cout << "\nOB = " << B.distanceToOrigin();
    cout << "\nAB = " << A.distanceToAnotherPoint(B);

    Point C;
    C.setValue(3,4);
    cout << "\n\nC"; C.display();

    if (A.isOverlap(C))
        cout << "\nA va C trung nhau";
    else
        cout << "\nA va C khong trung nhau";
    cout << "\nAC = " << A.distanceToAnotherPoint(C);
    return 0;
}
