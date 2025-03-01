#include "Student.h"
#include <vector>

void findTheBestStudent(vector<Student> List, int n)
{
    Student* max = &List[0];
    for (int i=1; i<n; i++)
    {
        if (List[i].getAverage() > max->getAverage())
            max = &List[i];
    }
    cout << "\n===STUDENT HAS MAX SCORE===\n";
    max->displayInfo();
}

int main()
{
    cout << "Enter number of student: ";
    int n;
    cin >> n;
    cin.ignore();

    // Tạo danh sách sinh viên
    vector<Student> List(n);
    for (int i=0; i<n; i++)
    {
        cout << "Enter infomation of student number " << i+1 << endl;
        List[i].inputInfo();
    }
    for (int i=0; i<n; i++)
        List[i].calculateAverage();

    // In danh sách sinh viên
    cout << "\n===LIST OF STUDENTS===\n";
    for (int i=0; i<n; i++)
        List[i].displayInfo();

    // Tìm sinh viên có điểm cao nhất
    findTheBestStudent(List, n);
    return 0;
}
