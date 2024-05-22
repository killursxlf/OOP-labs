#include <iostream>

using namespace std;


class Polygon {
public:
    virtual double area() = 0;
};


class Triangle : public Polygon {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double area() override
    {
        return (base * height) / 2;
    }
};


class Rectangle : public Polygon {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() override
    {
        return width * height;
    }
};


double printArea(Polygon* myPolygon)
{
    return myPolygon->area();
}


int main() {
    Triangle triangle(5, 4);
    Rectangle rectangle(6, 3);

    cout << "Area triangle: " << printArea(&triangle) << endl;
    cout << "Area rectangle: " << printArea(&rectangle) << endl;

    return 0;
}
