#include <Time.h>

int main()
{
    Time t1, t2;
    int count1 = 0, count2 = 0;
    cout << "NHAP THOI GIAN DAU\n";
    cin >> t1;

    cout << "NHAP THOI GIAN CONG THEM\n";
    cin >> t2;

    cout << "KET QUA: " << t1 + t2;
    return 0;
}
