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
    cout << "\n===LIST OF STUDENTS===\n";
    for (int i=0; i<n; i++)
        List[i].displayInfo();
    Student* max = &List[0];
    for (int i=1; i<n; i++)
    {
        if (List[i].getAverage() > max->getAverage())
            max = &List[i];
    }
    max->displayInfo();
    return 0;
}
