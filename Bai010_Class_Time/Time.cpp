#include "Time.h"

const int MAX_VALUE_OF_SECOND = 59;
const int MAX_VALUE_OF_MINUTE = 59;
const int MAX_VALUE_OF_HOUR = 23;
const int MIN_VALUE_OF_SECOND = 0;
const int MIN_VALUE_OF_MINUTE = 0;
const int MIN_VALUE_OF_HOUR = 0;
Time::Time(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}
int Time::getHour()
{
    return this->hour;
}
int Time::getMinute()
{
    return this->minute;
}
int Time::getSecond()
{
    return this->second;
}
void Time::setHour(int hour)
{
    this->hour = hour;
}
void Time::setMinute(int minute)
{
    this->minute = minute;
}
void Time::setSecond(int second)
{
    this->second = second;
}
istream& operator >> (istream& is, Time& time)
{
    int count = 0;
    do
    {
        if (count == 3)
        {
            cout << "Ban da nhap sai 3 lan, chuong trinh ket thuc!";
            return is;
        }
        else if (count > 0)
        {
            cout << "Thoi gian khong hop le, nhap lai\n";
        }

        cout << "Nhap gio: ";
        is >> time.hour;

        cout << "Nhap phut: ";
        is >> time.minute;

        cout << "Nhap giay: ";
        is >> time.second;
        count++;
    } while (time.isValid() == 0);

    return is;
}

ostream& operator << (ostream& os, Time time)
{
    os << time.hour << ":" << time.minute << ":" << time.second;
}
bool Time::isValid()
{
    return (this->hour >= MIN_VALUE_OF_HOUR && this->hour <= MAX_VALUE_OF_HOUR
            && this->minute >= MIN_VALUE_OF_MINUTE && this->minute <= MAX_VALUE_OF_MINUTE
            && this->second >= MIN_VALUE_OF_SECOND && this->second <= MAX_VALUE_OF_SECOND);
}
Time operator + (Time t1, Time t2)
{
    Time result = t1;
    result.second += t2.second;
    if (result.isValid() == false)
    {
        result.second -= MAX_VALUE_OF_SECOND+1;
        result.minute++;
    }

    result.minute += t2.minute;
    if (result.isValid() == false)
    {
        result.minute-= MAX_VALUE_OF_MINUTE+1;
        result.hour++;
    }

    result.hour += t2.hour;
    if (result.isValid() == false)
        result.hour -= MAX_VALUE_OF_HOUR+1;

    return result;
}
