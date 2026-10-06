#include "forge/core/Forge.h"
#include <iostream>

namespace forge {

    Forge::Forge(std::string nameInput, int resInt)
        : name(nameInput), resource(resInt)
    {
        std::cout << "Forge constructed: " << name << std::endl;
    }

    Forge::~Forge()
    {
        std::cout << "Forge destroyed: " << name << std::endl;
    }

    void Forge::SetResourceValue(int valueRes){resource.SetValue(valueRes);}
    int Forge::GetResourceValue() const {return resource.GetValue();}
}