#include "forge/core/Resource.h"

#include <iostream>

namespace forge
{
    Resource::Resource()
    {
        std::cout << "Resource acquired\n";
    }

    Resource::~Resource()
    {
        std::cout << "Resource released\n";
    }
}