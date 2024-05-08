#include <iostream>

using namespace std;

class Town {
private: 
    string Name;
    double area;
    double population;
    int post_index;

public: 
    Town() 
    {
        cout << "Default constructor work" << endl;
        Name = "empty";
        area = 0.0;
        population = 0.0;
        post_index = 0;
    }

    Town(string Text, double area_value, double population_value, int index) 
    {
        cout << "Constructor with parameters work" << endl;
        Name = Text;
        area = area_value;
        population = population_value;
        post_index = index;
    }

    Town(const Town& other_town) 
    {
        Name = other_town.Name;
        area = other_town.area;
        population = other_town.population;
        post_index = other_town.post_index;
        cout << "Work copy constructor" << endl;
    }

    ~Town() 
    {
        cout << "Distructor work" << endl;
    }

    void Print() 
    {
        cout << Name << endl;
        cout << "Area: " << area << endl;
        cout << "Population: " << population << endl;
        cout << "Post index: " << post_index << endl;
    }
};


int main() {
    
    Town MyTown;
    MyTown.Print();

    Town MyTown1("Mariupol", 500, 450000, 87500);
    MyTown1.Print();

    Town MyTown2(MyTown1);
    MyTown2.Print();
           
    return 0;
}
