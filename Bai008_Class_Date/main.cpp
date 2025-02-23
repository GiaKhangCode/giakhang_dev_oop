#include "DATE.h"

int main()
{
    DATE currentDate;
    currentDate.inputDate();
    cout << "Ngay vua duoc nhap la: ";
    currentDate.printDate();
    cout << "\nDay la " << currentDate.dayOfWeek() << endl;

    cout << "\nNhap vao so nguyen X, toi se xac dinh X ngay tiep theo la ngay nao: ";
    int x; cin >> x;
    DATE futureDate = getFutureDate(currentDate, x);
    cout << endl << x << " ngay sau ngay ";
    currentDate.printDate();
    cout << " la: " << futureDate.dayOfWeek() << " ";
    futureDate.printDate();

    return 0;
}





