#pragma once

#include "LeakedObjectDetector.h"

struct Bus
{
    Bus();
    ~Bus();
    
    int maximumSpeed { 110 };
    int numberOfSeats;
    std::string manufacturer = "MAN";
    float fuelConsumption = 20.3f;
    float fuelCapacity { 200.0f };

    void startEngine();
    void turnLeft(int angle);
    void openDoors(bool openAllDoors);
    void drive (int distance);

    void printThisBusInfo();

    JUCE_LEAK_DETECTOR(Bus)
};

