#pragma once
#include "Person.h"

class Student : public Person {
public:
    Student(string name, int age, string gender, float weight, int yearOfStudy) : Person(name, age, gender, weight) 
    {
        this->yearOfStudy = yearOfStudy;
    }

    int getYearOfStudy();

    void setYearOfStudy(int newYearOfStudy);

    void introduce();

    void increaseYearOfStudy();

    Person* getPerson(Person* person);

private:
    int yearOfStudy;
};
