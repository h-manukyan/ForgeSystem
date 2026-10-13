#include "forge/core/Resource.h"
#include <iostream>

bool check(bool condition, const char* message) {
    if (!condition) {
        std::cout << "FAILED: " << message << "\n";
        return false;
    }
    else {
        return true;
    }
}

bool testSuccessfulConsumption() {
    forge::Resource resource(10);

    if (!check(resource.Consume(3) == forge::ConsumeResult::Success, "Consume(3) should return Success")) {return false;}
    if (!check(resource.GetValue() == 7, "Resource value should be 7")) {return false;}

    return true;
}

bool testInsufficientResource() {
    forge::Resource resource(10);

    if (!check(resource.Consume(11) == forge::ConsumeResult::InsufficientResource, "Consume(11) should return InsufficientResource")) {return false;}
    if (!check(resource.GetValue() == 10, "Resource value should remain 10")) {return false;}

    return true;
}

bool testInvalidConsumption() {
    forge::Resource resource(10);
    if (!check(resource.Consume(-1) == forge::ConsumeResult::InvalidAmount, "Consume(-1) should return InvalidAmount")) {return false;}
    if (!check(resource.GetValue() == 10, "Resource value should remain 10")) {return false;}

    return true;
}

int main() {
    bool allPassed = true;

    if (!testSuccessfulConsumption()) {allPassed = false;}
    if (!testInsufficientResource()) {allPassed = false;}
    if (!testInvalidConsumption()) {allPassed = false;}

    if (!allPassed) {return 1;}

    std::cout << "All tests passed\n";
    return 0;
}