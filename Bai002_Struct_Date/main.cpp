#include <iostream>

using namespace std;

// 1. Định nghĩa cấu trúc Date
struct Date
{
    int day;
    int month;
    int year;
};

// 2. Hàm kiểm tra năm nhuận
bool isLeapYear(int Year)
{
    return (Year%4 == 0 && Year%100 != 0) || (Year%400 == 0);
}

// 3. Hàm trả về số ngày trong một tháng
int daysInMonth(int Month, int Year)
{
    switch(Month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(Year) ? 29 : 28;
        default:
            return 0;
    }
}

// 4. Hàm trả về ngày sau khi cộng X ngày
Date getFutureDate(Date current, int x)
{
    Date future = current;
    future.day += x;

    while (future.day > daysInMonth(future.month, future.year))
    {
        future.day -= daysInMonth(future.month, future.year);
        future.month++;

        if (future.month > 12)
        {
            future.month = 1;
            future.year++;
        }

    }

    return future;
}

void InputDate(Date &today)
{
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

}

bool checkDate(Date today)
{
    if (today.day < 1 || today.day > daysInMonth(today.month, today.year) || today.month < 1 || today.month > 12)
    {
        cout << "Ngay khong hop le!";
        return 1;
    }
    return 0;
}

void OutputDate(Date nextDay)
{
    cout << "Ngay tiep theo la: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;
}
int main()
{
    Date today;
    InputDate(today);

    if (checkDate(today)) return 0;

    int x;
    cout << "Nhap so ngay muon cong them: ";
    cin >> x;

    Date futureDay = getFutureDate(today, x);
    OutputDate(futureDay);

    return 0;
}
