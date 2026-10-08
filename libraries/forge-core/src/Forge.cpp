#include "forge/core/Forge.h"

#include <iostream>

namespace forge
{
    Forge::Forge(const std::string& input, int initialValue) : name(input), resource(initialValue) {std::cout << "Forge constructed: " << name << "\n";}
    Forge::~Forge(){std::cout << "Forge destroyed: " << name << "\n";}
    Forge::Forge(const Forge& other):name(other.name), resource(other.resource){}


    void Forge::SetResourceValue(int value){resource.SetValue(value);}
    int Forge::GetResourceValue() const{return resource.GetValue();}
    void Forge::AddResource(int amount){resource.Add(amount);}
    ConsumeResult Forge::ConsumeResource(int amount) {return resource.Consume(amount);}

    const std::string& Forge::GetName() const {return this->name;}
    void Forge::SetName(const std::string& newName){ if (!newName.empty()){this->name = newName;}}
}