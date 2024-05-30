#pragma once 
#include "Vector.h"

class VectorException : public runtime_error {
public:
    explicit VectorException(const string& message) : runtime_error(message) {}
};
