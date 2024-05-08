#include "Date.h"

int& Date::operator[](int index)
{
    if (index < 0 || index > 2)
    {
        throw out_of_range("Index is out of range.");
    }

    switch (index) 
    {
        case 0: 
            return day;
        case 1: 
            return month;
        case 2: 
            return year;
        default: 
            return day;
    }
}