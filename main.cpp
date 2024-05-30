#include "Date.h"

using namespace std;

istream& operator>>(istream& in, Date& date) 
{
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<<(ostream& out, const Date& date) 
{
    out << date.day << "." << date.month << "." << date.year;
    return out;
}


int main() {
    Date d1; 
    Date d2(02, 05, 2024);
    Date d3(d2); 

    cout << d1[0] << "." << d1[1] << "." << d1[2] << endl; 

    int day = d3();
    cout << "The day from d3 is " << day << endl;
    Date d4;
    cin >> d4;
    cout << d4 << endl;

    return 0;
}
