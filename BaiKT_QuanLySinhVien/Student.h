#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        string id;
        string name;
        int age;
        float mathScore;
        float literatureScore;
        float englishScore;
        float average;
    public:
        Student(string id = "None", string name = "None", int age = 0,
                float mathScore = 0, float literautreScore = 0, float englishScore = 0);
        void calculateAverage();
        string getID();
        string getName();
        int getAge();
        float getMathScore();
        float getLiteratureScore();
        float getEnglishScore();
        float getAverage();
        void setID(string id);
        void setName(string name);
        void setAge(int age);
        void setMathScore(float mathScore);
        void setLiteratureScore(float literatureScore);
        void setEnglishScore(float englishScore);
        void setAverage(float average);
        void inputInfo();
        void displayInfo();

};

#endif // STUDENT_H
