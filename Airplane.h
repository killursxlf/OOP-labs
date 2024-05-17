#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

using namespace std;

class Airplane {
private:
    string name; 
    double speed;    
    double height; 

public:


    string objectName;
    static int count;

    Airplane() : name("empty"), speed(0), height(0) {}

    Airplane(string name, double speed, double height)
    {
        this->name = name;
        this->speed = speed;
        this->height = height;
        count++;
        objectName = name;
    }

    const string& getName() { return name; }
    double getSpeed() { return speed; }
    double getHeight() { return height; }
    double getCount() { return count; }

    void setName(const string& name) { this->name = name; }
    void setSpeed(double speed) { this->speed = speed; }
    void setHeight(double height) { this->height = height; }

    void printInfo() 
    {
        cout << "Airplane: " << name << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Heaight: " << height << " m" << endl;
    }
};

int Airplane::count = 0;

#endif