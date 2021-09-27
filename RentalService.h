#pragma once

#include "LeakedObjectDetector.h"
#include "Bus.h"
#include "Computer.h"

struct RentalService
{
    RentalService();
    ~RentalService();

    Bus luxuryNightliner;
    Bus tourBus;
    ElectricGuitar cheapGuitar { "NoName", "Cheap Chinese Copy", 99.f };
    Computer rentalLaptop { "HP", "Windows 10" };

    void goOnTour(int tourDistance);    
    void prepareComputer();

    JUCE_LEAK_DETECTOR(RentalService)
};


