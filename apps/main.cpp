#include <iostream>
#include <string>

#include "forge/core/Forge.h"

std::string GetConsumeMessage(forge::ConsumeResult result)
{
    switch (result)
    {
        case forge::ConsumeResult::Success:
            return "Consumption successful";

        case forge::ConsumeResult::InvalidAmount:
            return "Invalid amount";

        case forge::ConsumeResult::InsufficientResource:
            return "Not enough resource";
    }

    return "Unknown result";
}

int main()
{
    forge::Forge forge1("ForgeOne", 100);
    std::cout << "Initial resource: " << forge1.GetResourceValue() << "\n";

    forge1.AddResource(50);
    std::cout << "After adding 50: " << forge1.GetResourceValue() << "\n";

    forge::ConsumeResult result = forge1.ConsumeResource(30);

    std::cout << GetConsumeMessage(result) << "\n";
    std::cout << "Resource remaining: " << forge1.GetResourceValue() << "\n";

    result = forge1.ConsumeResource(-10);
    std::cout << GetConsumeMessage(result) << "\n";

    result = forge1.ConsumeResource(200);
    std::cout << GetConsumeMessage(result) << "\n";

    std::cout << "Final resource: " << forge1.GetResourceValue() << "\n";

    return 0;
}