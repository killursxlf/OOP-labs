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

    string getName();
    int getAge();
    string getGender(); 
    float getWeight();


    void setName(string newName);
    void setAge(int newAge);
    void setGender(string newGender);
    void setWeight(float newWeight);

    void introduce();

private:
    string name;
    int age;
    string gender;
    float weight;
};
