#include "Vector.h"

int& Vector::operator[](size_t index)
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

size_t Vector::operator()()
{
    return data.size();
}

Vector Vector::operator+(int value) 
{
    Vector result(*this);
    for (auto& elem : result.data)
    {
        elem += value;
    }
    return result;
}

void Vector::remove_from_end(size_t n)
{
    if (n > data.size())
    {
        throw out_of_range("Number of elements to remove more than vector size");
    }
    data.resize(data.size() - n);
}

void Vector::add(int value)
{
    data.push_back(value);
}

void Vector::print()
{
    for (const auto& elem : data)
    {
        cout << elem << " ";
    }
    cout << endl;
}
