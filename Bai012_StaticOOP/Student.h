#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        int id;
        string name;
        static int studentCount;
    public:
        Student(int id = 0, string name = "None");
        void displayInformation();
        static int getStudentCount();
};

#endif // STUDENT_H
