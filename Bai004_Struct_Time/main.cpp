#include <iostream>

using namespace std;

// 1. Định nghĩa cấu trúc Time
struct Time
{
    int hour;
    int minute;
    int second;
};

// 2. Hàm nhập vào một thời điểm
void InputTime(Time &t)
{
    cin >> t.hour >> t.minute >> t.second;
}

// 3. Hàm cộng hai khoảng thời gian
Time congThoiGian(Time t1, Time t2)
{
    Time res = t1;
    res.second += t2.second;
    res.minute += t2.minute;
    res.hour += t2.hour;

    while (res.second > 59)
    {
        res.minute++;
        res.second-=60;
    }

    while (res.minute > 59)
    {
        res.hour++;
        res.minute-=60;
    }

    while (res.hour > 23)
        res.hour-=24;

    return res;
}

// 4. Hàm xuất 1 thành phần
void OutputElement(int n)
{
    if (n<10) cout << 0 << n;
    else cout << n;
}

// 5. Hàm xuất một thời gian
void outputTime(Time t)
{
    OutputElement(t.hour);
    cout << ":";
    OutputElement(t.minute);
    cout << ":";
    OutputElement(t.second);
}

// 6. Hàm kiểm tra thời gian
bool checkTime(Time t)
{
    if (t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59 || t.second < 0 || t.second > 59)
    {
        cout << "Thoi gian khong hop le!";
        return 0;
    }
    return 1;
}

// 7. Hàm xuất kết quả
void Output(Time t1, Time t2)
{
    outputTime(t1);
    cout << " + ";

    outputTime(t2);
    cout << " = ";

    Time res = congThoiGian(t1, t2);
    outputTime(res);
}

int main()
{
    Time t1, t2;

    cout << "NHAP VAO MOT THOI DIEM (hh mm ss): ";
    InputTime(t1);

    if (checkTime(t1) == 0) return 0;

    cout << "NHAP KHOANG THOI GIAN MUON CONG THEM (hh mm ss): ";
    InputTime(t2);

    if (checkTime(t2) == 0) return 0;

    cout << "==========================\nKET QUA: ";
    Output(t1, t2);

    return 0;
}
