#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Vector {
private:
    vector<int> data;
public:

    Vector(const initializer_list<int>& init_list) : data(init_list) {}

    int& operator[](size_t index);

    size_t operator()();

    Vector operator+(int value);

    void remove_from_end(size_t n);

    void add(int value);

    void print();
};
