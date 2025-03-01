#include "Student.h"
#include <vector>

int main()
{
    cout << "Enter number of student: ";
    int n;
    cin >> n;
    cin.ignore();
    vector<Student> List(n);
    for (int i=0; i<n; i++)
        List[i].inputInfo();
    for (int i=0; i<n; i++)
        List[i].calculateAverage();
    cout << "===LIST OF STUDENTS===\n";
    for (int i=0; i<n; i++)
        List[i].displayInfo();
    return 0;
}
