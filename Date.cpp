#include "Date.h"

int& Date::operator[](int index)
{
    if (index < 0 || index > 2)
    {
        throw out_of_range("Index is out of range.");
    }

    switch (index) 
    {
        case DAY_INDEX: 
            return day;
        case MONTH_INDEX: 
            return month;
        case YEAR_INDEX: 
            return year;
        default: 
            return day;
    }
}