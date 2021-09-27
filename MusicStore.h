#pragma once

#include "LeakedObjectDetector.h"

#include "ElectricGuitar.h"
#include "Computer.h"

struct MusicStore
{
    MusicStore();
    ~MusicStore();

    ElectricGuitar lesPaul { "Gibson", "Les Paul", 3289.99f };
    ElectricGuitar stratocaster { "Fender", "Stratocaster", 2399.99f };
    Computer officePc { "Asus", "Windows 95" };

    float valueOfGuitars();
    float calculateBlackFridayPrice(int discount, float originalPrice);

    void printThisGuitarValue();
    void printThisBlackFidayPrice(int discount, float originalPrice);

    void printThisLesPaulBlackFridayPrice(int discount);

    JUCE_LEAK_DETECTOR(MusicStore)
};


