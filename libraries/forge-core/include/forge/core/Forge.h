#pragma once

#include <string>
#include "Resource.h"

namespace forge {

    class Forge {
    private:
        std::string name;
        Resource resource;

    public:
        Forge(std::string nameInput, int resInt);
        ~Forge();

        void SetResourceValue(int valueRes);
        int GetResourceValue() const;
    };

}
