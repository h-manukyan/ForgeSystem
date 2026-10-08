#include "forge/core/Resource.h"

#include <iostream>

namespace forge
{
    Resource::Resource(int initialValue) : value(initialValue >= 0 ? initialValue : 0) {std::cout << "Resource acquired\n";}

    Resource::~Resource() {std::cout << "Resource released\n";}

    void Resource::SetValue(int x){if (x >= 0){value = x;}}
    int Resource::GetValue() const{return value;}

    void Resource::Add(int amount){if (amount >= 0){value += amount;}}
    ConsumeResult Resource::Consume(int amount)
    {
        if (amount < 0)
            return ConsumeResult::InvalidAmount;

        if (amount > value)
            return ConsumeResult::InsufficientResource;

        value -= amount;
        return ConsumeResult::Success;
    }
}