#include "Student.h"

int Student::getYearOfStudy() { return yearOfStudy; }

void Student::setYearOfStudy(int newYearOfStudy) { yearOfStudy = newYearOfStudy; }

void Student::introduce()
{
    Person::introduce();
    cout << "Years of study: " << yearOfStudy << endl;
}

void Student::increaseYearOfStudy()
{
    yearOfStudy++;
}

Person* Student::getPerson(Person* person)
{
    return new Person(*person);
}
