#include <iostream>
#include "ElectricGuitar.h"


ElectricGuitar::ElectricGuitar(std::string guitarManufacturer, std::string guitarName, float guitarPrice) : 
manufacturer(guitarManufacturer),
name(guitarName), 
price(guitarPrice) 
{ 
    std::cout << "CONSTRUCTING ElectricGuitar " << manufacturer << " " << name << " $" << price << std::endl;
}

ElectricGuitar::~ElectricGuitar()
{
    std::cout << "DESTRUCTING ElectricGuitar " << manufacturer << " " << name << std::endl;
    string1.breakString();
}

void ElectricGuitar::plugIn(std::string cableColor)
{
    std::cout << "You have plugged the " << cableColor << " cable into the " << color <<  " " << name <<std::endl;
}

void ElectricGuitar::selectPickup(int pickup)
{
    std::cout << "Switched to pickup " << pickup << std::endl;
}

void ElectricGuitar::changeVolume(float volume)
{
    std::cout << "Changed volume of " << name << " to " << volume << std::endl;
}

void ElectricGuitar::turnUpVolume()
{
    for (int i = 0; i <= 20; ++i )
    {
        changeVolume( i * 0.5f );
    }
}

void ElectricGuitar::printThisPrice()
{
    std::cout << "This Price: " << this->price << std::endl;
}

void ElectricGuitar::printThisStringManufacturer()
{
    std::cout << "This String-Manufacturer: " << this->string1.manufacturer << std::endl;
} 
    
void ElectricGuitar::GuitarString::breakString()
{
    std::cout << "String " << number << " just broke!! ";
    if (isWound)
    {
        std::cout << "This is a wound string - how did that happen??" << std::endl;;
    }
    else  
    {
        std::cout << std::endl;
    }
}

void ElectricGuitar::GuitarString::tuneString(float referencePitch)
{
    std::cout << "String " << number << " is tuned to " << referencePitch << " Hz" <<std::endl;
}

void ElectricGuitar::GuitarString::pluckString(int fret)
{
    std::cout << "Plucked String " << number << " / fret " << fret << std::endl;
}
