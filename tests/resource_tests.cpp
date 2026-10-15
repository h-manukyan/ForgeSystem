#include "forge/core/Resource.h"
#include <iostream>
#include <limits>
#include <string>

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

//Resource amount setting test function
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

//Overflow checking functions
bool testOverflow() {
    forge::Resource resource(10);

    if (!check(resource.Add(std::numeric_limits<int>::max()) == forge::ConsumeResult::Overflow, "The resource amount exceeds the INT limits")) {return false;}

    return true;
}


bool testOverflowBoundary()
{
    const int maxValue = std::numeric_limits<int>::max();

    // Case A: Adding exactly up to INT_MAX should succeed.
    forge::Resource resource(maxValue - 5);

    if (!check(resource.Add(5) == forge::ConsumeResult::Success,"Adding up to INT_MAX should succeed")) {return false;}
    if (!check(resource.GetValue() == maxValue,"Resource value should equal INT_MAX")) {return false;}

    // Case B: Adding one beyond INT_MAX should fail.
    forge::Resource resource2(maxValue - 5);

    if (!check(resource2.Add(6) == forge::ConsumeResult::Overflow,"Adding beyond INT_MAX should return Overflow")) {return false;}
    if (!check(resource2.GetValue() == maxValue - 5,"Resource value should remain unchanged after overflow")) {return false;}

    return true;
}


// Main execution part
int main(int argc, char* argv[]) {
    bool allPassed = true;

    if (argc == 2)
    {   
        std::string testName = argv[1];

        if (testName == "successful-consumption") return reportTest("Successful consumption",testSuccessfulConsumption()) ? 0 : 1;
        if (testName == "insufficient-resource") return reportTest("Insufficient resource",testInsufficientResource()) ? 0 : 1;
        if (testName == "invalid-consumption") return reportTest("Invalid consumption",testInvalidConsumption()) ? 0 : 1;
        if (testName == "add-resource") return reportTest("Add resource",testAddResource()) ? 0 : 1;
        if (testName == "set-value") return reportTest("Set value",testSetValue()) ? 0 : 1;
        if (testName == "overflow-test") return reportTest("Overflow",testOverflow()) ? 0 : 1;
        if (testName == "overflow-boundary") return reportTest("Overflow boundary",testOverflowBoundary()) ? 0 : 1;

        std::cerr << "Unknown test: " << testName << "\n";
        return 2;
    }

    if (argc > 2)
    {
        std::cerr << "Usage: forge-tests [test-name]\n";
        return 2;
    }

    if (!reportTest("Successful consumption",testSuccessfulConsumption())) {allPassed = false;}
    if (!reportTest("Insufficient resource",testInsufficientResource())) {allPassed = false;}
    if (!reportTest("Invalid consumption",testInvalidConsumption())) {allPassed = false;}
    if (!reportTest("Add resource",testAddResource())) {allPassed = false;}
    if (!reportTest("Set value",testSetValue())) {allPassed = false;}
    if (!reportTest("Overflow",testOverflow())) {allPassed = false;}
    if (!reportTest("Overflow boundary", testOverflowBoundary())) {allPassed = false;}

    if (allPassed) {std::cout << "All tests passed\n";} else {std::cout << "Some tests failed\n"; return allPassed ? 0 : 1;}

}
