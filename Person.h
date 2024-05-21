#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(std::string name, int age, string gender, float weight) 
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->weight = weight;
    }

    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    float getWeight() { return weight; }


    void setName(string newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setGender(string newGender) { gender = newGender; }
    void setWeight(float newWeight) { weight = newWeight; }


    void introduce()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << endl;
    }

private:
    string name;
    int age;
    string gender;
    float weight;
};
