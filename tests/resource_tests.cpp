#include "forge/core/Resource.h"
#include <iostream>

bool testSuccessfulConsumption() {
    forge::Resource resource(10);

    if (resource.Consume(3) != forge::ConsumeResult::Success) {return false;}
    else if (resource.GetValue() != 7) {return false;}
    else {return true;}
}

bool testInsufficientResource() {
    forge::Resource resource(10);

    if (resource.Consume(11) != forge::ConsumeResult::InsufficientResource) {return false;}
    else if (resource.GetValue() != 10) {return false;}
    else {return true;}
}

int main() {

    if (!testSuccessfulConsumption()) {return 1;}
    if (!testInsufficientResource()) {return 2;}

    return 0;
}