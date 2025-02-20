#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

using namespace std;

class DATE
{
private:
    int day;
    int month;
    int year;
public:
    void inputDate();
    void printDate();
    string dayOfWeek();
    int getDay();
    int getMonth();
    int getYear();
    friend DATE getFutureDate(DATE current, int x);
};


#endif // DATE_H
