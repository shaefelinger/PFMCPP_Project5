#include <iostream>
#include "RentalService.h"

RentalService::RentalService()
{
    std::cout << "CONSTRUCTING Rental Service" << std::endl;
    goOnTour(50);
}

RentalService::~RentalService()
{
    std::cout << "DESTRUCTING Rental Service" << std::endl;
}

void RentalService::goOnTour(int tourDistance)
{
    std::cout << "Tour Start:" << std::endl;
    tourBus.drive(tourDistance);
}

void RentalService::prepareComputer()
{
    std::cout << "Preparing " << rentalLaptop.manufacturer << " Computer for rental:" << std::endl; 
    rentalLaptop.showInfo();
    rentalLaptop.eraseDisk("C:");
    rentalLaptop.runProgram("Pro Tools", 2);
}


