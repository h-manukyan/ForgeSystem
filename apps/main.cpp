#include "forge/core/Forge.h"
#include <iostream>

int main()
{
    {
        forge::Forge forge1("ForgeOne", 123);
        //forge1.SetResourceValue(100);
        int x = forge1.GetResourceValue();
        std::cout << x << std::endl;

        // Forge exists here
    }

    // Forge no longer exists here

    return 0;
}