#include "Vector.h"

int main() {
    try
    {
        Vector<int> intVec = { 1, 2, 3, 4, 5 };
        cout << "Integer Vector:" << endl;

        cout << "Element at index 2: " << intVec[2] << endl;
        cout << "Size of vector: " << intVec() << endl;

        Vector<int> intVec2 = intVec + 10;
        cout << "Vector after adding constant 10 to all elements: ";
        intVec2.print();

        intVec2.remove_from_end(2);
        cout << "Vector after removing 2 elements from the end: ";
        intVec2.print();

        cout << "Try get element with index 10: ";
        cout << intVec2[10];
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        Vector<double> doubleVec = { 1.1, 2.2, 3.3, 4.4, 5.5 };

        cout << "\nDouble Vector:" << endl;
        cout << "Element at index 2: " << doubleVec[2] << endl;
        cout << "Size of vector: " << doubleVec() << endl;

        Vector<double> doubleVec2 = doubleVec + 1.5;
        cout << "Vector after adding constant 1.5 to all elements: ";
        doubleVec2.print();

        doubleVec2.remove_from_end(2);
        cout << "Vector after removing 2 elements from the end: ";
        doubleVec2.print();

        cout << "Try get element with index 10: ";
        cout << doubleVec2[10] << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
