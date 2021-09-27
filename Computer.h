#pragma once

#include "LeakedObjectDetector.h"

struct Computer
{
    Computer(std::string computerManufacturer, std::string computerOS);
    ~Computer();

    std::string manufacturer = "Apple";
    std::string operatingSystem = "MacOS";
    int amountOfRam;
    float processorSpeed {2.4f};
    int sizeOfDisk = 4;

    void runProgram(std::string program, int priority);
    void shutDown();
    void eraseDisk(std::string volumeName);
    void showInfo();
    void powerOffCountdown();

    struct Application
    {
        std::string name = "Logic Pro";
        std::string manufacturer = "Apple";
        std::string appType = "audio";
        float size = 1.1f;
        std::string version = "10.5";

        void start();
        void close();
        void install(std::string filePath);

        void printThisApplicationSize();
    };
    Application logicPro;

    JUCE_LEAK_DETECTOR(Computer)
};

