#pragma once
#include "Person.h"

class Student : public Person {
public:
    Student(string name, int age, string gender, float weight, int yearOfStudy) : Person(name, age, gender, weight) 
    {
        this->yearOfStudy = yearOfStudy;
    }

    int getYearOfStudy() const { return yearOfStudy; }

    void setYearOfStudy(int newYearOfStudy) { yearOfStudy = newYearOfStudy; }

    void introduce() 
    {
        Person::introduce();
        cout << "Years of study: " << yearOfStudy << endl;
    }

    void increaseYearOfStudy() 
    {
        yearOfStudy++;
    }

    Person* getPerson(Person* person)
    {
        return new Person(*person);
    }

private:
    int yearOfStudy;
};
