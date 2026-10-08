#pragma once

#include <string>

#include "Resource.h"

namespace forge
{

    class Forge
    {
    private:
        std::string name;
        Resource resource;

    public:
        Forge(const std::string& input, int initialValue);
        ~Forge();
        Forge(const Forge& other);

        void SetResourceValue(int value);
        int GetResourceValue() const;

        void AddResource(int amount);
        ConsumeResult ConsumeResource(int amount);

        const std::string& GetName() const;
        void SetName(const std::string& newName);
    };
}