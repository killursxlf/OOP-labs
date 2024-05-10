#pragma once
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>

const int DAY_INDEX = 0;
const int MONTH_INDEX = 1;
const int YEAR_INDEX = 2;

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:

    Date()
    {
        day = 1;
        month = 1;
        year = 1978;
    }
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    ~Date() {}


    int& operator[](int index);
    int operator()() const { return day; }
    friend istream& operator>>(istream& in, Date& date);
    friend ostream& operator<<(ostream& out, const Date& date);
};


#endif DATE_H_INCLUDED