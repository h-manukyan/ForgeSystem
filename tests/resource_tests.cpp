
#include "forge/core/Resource.h"

#include <iostream>

// Condition checking function
bool check(bool condition, const char* message)
{
    if (!condition)
    {
        std::cout << "FAILED: " << message << "\n";
        return false;
    }
    else
    {
        return true;
    }
}

// Consumption testing functions
bool testSuccessfulConsumption()
{
    forge::Resource resource(10);

    if (!check(resource.Consume(3) == forge::ConsumeResult::Success, "Consume(3) should return Success")) {return false;}
    if (!check(resource.GetValue() == 7, "Resource value should be 7")) {return false;}

    return true;
}

bool testInsufficientResource()
{
    forge::Resource resource(10);

    if (!check(resource.Consume(11) == forge::ConsumeResult::InsufficientResource, "Consume(11) should return InsufficientResource")) {return false;}
    if (!check(resource.GetValue() == 10, "Resource value should remain 10")) {return false;}

    return true;
}

bool testInvalidConsumption()
{
    forge::Resource resource(10);

    if (!check(resource.Consume(-1) == forge::ConsumeResult::InvalidAmount, "Consume(-1) should return InvalidAmount")) {return false;}
    if (!check(resource.GetValue() == 10, "Resource value should remain 10")) {return false;}

    return true;
}

// Addition testing functions
bool testAddResource()
{
    forge::Resource resource(10);

    if (!check(resource.Add(5) == forge::ConsumeResult::Success, "Add(5) should return Success")) {return false;}
    if (!check(resource.GetValue() == 15, "Resource value should be 15 after Add(5)")) {return false;}

    if (!check(resource.Add(-3) == forge::ConsumeResult::InvalidAmount, "Add(-3) should return InvalidAmount")) {return false;}
    if (!check(resource.GetValue() == 15, "Resource value should remain 15 after Add(-3)")) {return false;}

    if (!check(resource.Add(0) == forge::ConsumeResult::Success, "Add(0) should return Success")) {return false;}
    if (!check(resource.GetValue() == 15, "Resource value should remain 15 after Add(0)")) {return false;}

    return true;
}

bool testSetValue()
{
    forge::Resource resource(10);

    resource.SetValue(25);
    if (!check(resource.GetValue() == 25, "Resource value should be 25 after SetValue(25)")) {return false;}

    resource.SetValue(-5);
    if (!check(resource.GetValue() == 25, "Resource value should remain 25 after SetValue(-5)")) {return false;}

    return true;
}

// Test reporting function
bool reportTest(const char* testName, bool result)
{
    if (result) {std::cout << "PASS: " << testName << "\n";} else {std::cout << "FAIL: " << testName << "\n";}

    return result;
}

// Main execution part
int main(int argc, char* argv[])
{
    bool allPassed = true;

    if (!reportTest("Successful consumption", testSuccessfulConsumption())) allPassed = false;
    if (!reportTest("Insufficient resource", testInsufficientResource())) allPassed = false;
    if (!reportTest("Invalid consumption", testInvalidConsumption())) allPassed = false;
    if (!reportTest("Add resource", testAddResource())) allPassed = false;
    if (!reportTest("Set value", testSetValue())) allPassed = false;
    if (!allPassed) return 1;

    std::cout << "All tests passed\n\n\n";

    std::cout << "argc = " << argc << "\n";
    std::cout << "argv[1] = " << argv[1] << "\n";
    return 0;
}
