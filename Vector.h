#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    vector<T> data;
public:
    Vector(const initializer_list<T>& init_list) : data(init_list) {}

    T& operator[](size_t index);

    size_t operator()();

    Vector<T> operator+(T value);

    void remove_from_end(size_t n);

    void add(T value);

    void print();
};
