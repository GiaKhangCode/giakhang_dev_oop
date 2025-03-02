#include "Student.h"

int main()
{
    Student A(1, "HIEUTHUHAI");
    Student B(2, "Rhyder");
    Student C(3, "Quang Hung MasterD");

    cout << "===DANH SACH SINH VIEN===\n\n";
    cout << "Ma sinh vien\t|Ten sinh vien\n";
    A.displayInformation();
    B.displayInformation();
    C.displayInformation();
    cout << "\nTONG SO SINH VIEN: " << Student::getStudentCount();

    return 0;
}
