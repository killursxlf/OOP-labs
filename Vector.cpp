#include "Vector.h"

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index >= data.size())
    {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Vector<T>::operator()()
{
    return data.size();
}

template <typename T>
Vector<T> Vector<T>::operator+(T value) 
{
    Vector result(*this);
    for (auto& elem : result.data)
    {
        elem += value;
    }
    return result;
}

template <typename T>
void Vector<T>::remove_from_end(size_t n)
{
    if (n > data.size())
    {
        throw out_of_range("Number of elements to remove more than vector size");
    }
    data.resize(data.size() - n);
}

template <typename T>
void Vector<T>::add(T value)
{
    data.push_back(value);
}

template <typename T>
void Vector<T>::print()
{
    for (const auto& elem : data)
    {
        cout << elem << " ";
    }
    cout << endl;
}

template class Vector<int>;
template class Vector<double>;
template class Vector<string>;
