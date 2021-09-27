#include <iostream>
#include "Bus.h"

Bus::Bus() : 
numberOfSeats(24) 
{
    std::cout << "CONSTRUCTING Bus" << std::endl;
}

Bus::~Bus() 
{
    std::cout << "DESTRUCTING Bus" << std::endl;
}

void Bus::startEngine()
{
    std::cout << "Engine of Bus started. The maximum speed is " << maximumSpeed << " km/h" <<std::endl;
}

void Bus::turnLeft(int angle)
{
    std::cout << "Turned left " << angle << " degrees" << std::endl;
}

void Bus::openDoors(bool openAllDoors)
{
    if(openAllDoors)
    {
        std::cout << "Opened all doors" << std::endl;
    }
    else 
    {
        std::cout << "Opened a single door" << std::endl;
    }
}

void Bus::drive (int distance) 
{
    float fuelLeft, fuelUsed;
    int i = 0; 
    while ( i <= distance )
    {
        fuelUsed =  i * fuelConsumption / 100;
        fuelLeft =  fuelCapacity - fuelUsed;

        if ( fuelLeft < 0 ) 
        {
            std::cout << "YOU RAN OUT OF FUEL!!!" << std::endl;
            break;
        }

        std::cout << "You have driven " << i << " Km and used " << fuelUsed << " liters of fuel. You have " << fuelLeft << " liters left." << std::endl;
        i += 50;        
    }
}

void Bus::printThisBusInfo()
{
    std::cout << "This Bus made by " << this->manufacturer << " has " << this->numberOfSeats << " Seats and a maxiumum speed of " << this->maximumSpeed << " km/h" << std::endl;
}

