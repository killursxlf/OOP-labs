#include "Complex.h"
#include<iostream>

using namespace std;

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(2.0, 5.0);


    Complex c3 = c1 - c2;
    c3.print();

    char znak = c1 > c2 ? '>' : '<';
    cout << "c1 " << znak << " c2" << endl;

    --c1;
    cout << "After --: ";
    c1.print();

    c1--;
    cout << "After --: ";
    c1.print();

    c1 = c2;
    cout << "c1 after = c2: ";
    c1.print();

    return 0;
}