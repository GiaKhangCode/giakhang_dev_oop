#include "Student.h"

Student::Student(string id, string name, int age,
                float mathScore, float literatureScore, float englishScore)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->mathScore = mathScore;
    this->literatureScore = literatureScore;
    this->englishScore = englishScore;
}
void Student::calculateAverage()
{
    average = (mathScore*2 + literatureScore*2 + englishScore)/5;
}
string Student::getID()
{
    return id;
}
string Student::getName()
{
    return name;
}
int Student::getAge()
{
    return age;
}
float Student::getMathScore()
{
    return mathScore;
}
float Student::getLiteratureScore()
{
    return literatureScore;
}
float Student::getEnglishScore()
{
    return englishScore;
}
float Student::getAverage()
{
    return average;
}
void Student::setID(string id)
{
    this->id = id;
}
void Student::setName(string name)
{
    this->name = name;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setMathScore(float mathScore)
{
    this->mathScore = mathScore;
}
void Student::setLiteratureScore(float literatureScore)
{
    this->literatureScore = literatureScore;
}
void Student::setEnglishScore(float englishScore)
{
    this->englishScore = englishScore;
}
void Student::setAverage(float average)
{
    this->average = average;
}
void Student::inputInfo()
{
    cout << "Enter ID: ";
    getline(cin, id);
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter math score: ";
    cin >> mathScore;
    cout << "Enter literature score: ";
    cin >> literatureScore;
    cout << "Enter English score: ";
    cin >> englishScore;
    cin.ignore();
}
void Student::displayInfo()
{
    cout << "Student ID: " << id << endl
        << "Name: " << name << endl
        << "Age: " << age << endl
        << "Math: " << mathScore << endl
        << "Literature: " << literatureScore << endl
        << "English: " << englishScore << endl
        << "Average: " << average << endl;
}
