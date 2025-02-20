#include "DATE.h"

bool isLeapYear(DATE D)
{
    int year = D.getYear();
    return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
}


int getM(DATE D)
{
    int month = D.getMonth();
    if (month == 1 || month == 2)
        return month+12;
    return month;
}

int getK(DATE D)
{
    int month = D.getMonth(), year = D.getYear();
    if (month < 3)
        return (year-1)%100;
    return year%100;
}

int getJ(DATE D)
{
    int year = D.getYear();
    return year/100;
}

int getH(DATE D)
{
    int day = D.getDay(), month = D.getMonth(), year = D.getYear();
    int q = day, m = getM(D), K = getK(D), J = getJ(D);
    return ((q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J)%7);

}

int getNumOfDaysInMonth(DATE D)
{
    int month = D.getMonth(), year = D.getYear();
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(D) ? 29 : 28;
        default:
            return 0;
    }
}

DATE getFutureDate(DATE current, int x)
{
    DATE future = current;
    future.day += x;

    while (future.day > getNumOfDaysInMonth(future))
    {
        future.day -= getNumOfDaysInMonth(future);
        future.month++;

        if (future.month > 12)
        {
            future.month = 1;
            future.year++;
        }
    }

    return future;
}


int DATE::getDay()
{
    return this->day;
}
int DATE::getMonth()
{
    return this->month;
}
int DATE::getYear()
{
    return this->year;
}

void DATE::inputDate()
{
    cout << "Nhap vao ngay, thang, nam (dd mm yyyy): ";
    cin >> this->day >> this->month >> this->year;
}

void DATE::printDate()
{
    cout << "ngay " <<day << " thang " << month << " nam " << year;
}


string DATE::dayOfWeek()
{
    string daysOfWeek[7] = {"thu bay", "chu nhat", "thu hai", "thu ba", "thu tu", "thu nam", "thu sau"};
    int h = getH(*this);
    return daysOfWeek[h];
}


