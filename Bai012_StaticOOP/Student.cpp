#include "Student.h"

int Student::studentCount = 0;

Student::Student(int id, string name)
{
    this->id = id;
    this->name = name;
    studentCount++;
}
void Student::displayInformation()
{
    cout << id << "\t\t|" << name << endl;
}
int Student::getStudentCount()
{
    return studentCount;
}
