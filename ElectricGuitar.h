#pragma once

#include "LeakedObjectDetector.h"

struct ElectricGuitar
{
    ElectricGuitar(std::string guitarManufacturer, std::string guitarName, float guitarPrice);
    ~ElectricGuitar();

    std::string manufacturer; 
    std::string name;
    float price;    
    std::string color = "blue";
    int numberOfStrings = 6;

    void plugIn(std::string cableColor);
    void selectPickup(int pickup);
    void changeVolume(float volume);
    void turnUpVolume();

    void printThisPrice();
    void printThisStringManufacturer();

    struct GuitarString
    {
        std::string manufacturer = "Ernie Ball";
        int number = 1;
        bool isWound = true;
        float width = 0.52f;
        std::string material = "steel";

        void breakString();
        void tuneString (float referencePitch);
        void pluckString(int fret); 
    };

    GuitarString string1; 
    JUCE_LEAK_DETECTOR(ElectricGuitar)
};

