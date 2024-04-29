#include "Complex.cpp"

using namespace std;

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(2.0, 5.0);


    Complex c3 = c1 - c2;
    cout << "c1 - c2 = "; c3.print();

    if (c1 > c2)
        cout << "c1 більше за c2" << endl;
    else
        cout << "c1 не більше за c2" << endl;


    --c1;
    cout << "Після декременту: "; c1.print();

    c1--;
    cout << "Після декременту: "; c1.print();

    c1 = c2;
    cout << "c1 після присвоєння c2: "; c1.print();

    return 0;
}