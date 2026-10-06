#include "forge/core/Resource.h"

#include <iostream>

namespace forge
{
    Resource::Resource(int resInt) : value(resInt >= 0 ? resInt : 0)
    {
        std::cout << "Resource acquired\n";
    }

    Resource::~Resource()
    {
        std::cout << "Resource released\n";
    }

    void Resource::SetValue(int x) {
        if (x >= 0) {value = x;}
    }

    int Resource::GetValue() const {return value;}
}