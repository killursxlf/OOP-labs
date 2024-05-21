#include "Person.h"

string Person::getName() { return name; }
int Person::getAge() { return age; }
string Person::getGender() { return gender; }
float Person::getWeight() { return weight; }


void Person::setName(string newName) { name = newName; }
void Person::setAge(int newAge) { age = newAge; }
void Person::setGender(string newGender) { gender = newGender; }
void Person::setWeight(float newWeight) { weight = newWeight; }

void Person::introduce()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Weight: " << weight << endl;
}
