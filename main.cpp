#include "Vector.h"

int main() {
    try 
    {
        Vector vec = { 1, 2, 3, 4, 5 };

        cout << "Element at index 2: " << vec[2] << endl;

        cout << "Size of vector: " << vec() << endl;

        Vector vec2 = vec + 10;
        cout << "Vector after adding constant 10 to all elements ";
        vec2.print();

        vec2.remove_from_end(2);
        cout << "Vector after removing 2 elements from the end: ";
        vec2.print();

        cout << "Try get element with index 10: ";
        cout << vec2[10] << endl;
    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
