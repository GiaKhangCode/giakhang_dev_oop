#ifndef TIME_H
#define TIME_H
#include <iostream>

using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int hour = 0, int minute = 0, int second = 0);
        int getHour();
        int getMinute();
        int getSecond();
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
        friend istream& operator >> (istream&, Time&);
        friend ostream& operator << (ostream&, Time);
        bool isValid();
        friend Time operator + (Time, Time);
//        friend Time operator - (Time, Time);
};

#endif // TIME_H
