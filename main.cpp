#include <iostream>
#include "Town.h"
#include <vector>

using namespace std;

int main() {

    Town MyTown;
    MyTown.Print();

    Town MyTown1("Mariupol", 500, 450000, 87500);
    MyTown1.Print();

    Town MyTown2(MyTown1);
    MyTown2.Print();

    vector<Town> Towns;
    Towns.push_back(MyTown1);
    Towns.push_back(MyTown2);
    Towns.push_back(Town("Kiyv", 1000, 2000000, 0100));

    for (int i = 0; i < Towns.size(); i++)
    {
        cout << "Town " << i + 1 << ":" << endl;
        Towns[i].Print();
        cout << endl;
    }

    return 0;
}
