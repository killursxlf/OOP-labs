#include"Town.h"

void Town::Print()
{
    cout << "Name: " << Name;
    cout << " Area: " << area;
    cout << " Population: " << population;
    cout << " Post index: " << post_index << endl;
}

void Town::set_name(string text)
{
    Name = text;
}

void Town::set_area(double value)
{
    area = value;
}

void Town::set_population(double value)
{
    population = value;
}

void Town::set_index(int index)
{
    post_index = index;
}

string Town::get_name()
{
    return Name;
}

double Town::get_area()
{
    return area;
}

double Town::get_population()
{
    return population;
}

int Town::get_index()
{
    return post_index;
}
