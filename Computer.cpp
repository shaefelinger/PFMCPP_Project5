#include <iostream>
#include "Computer.h"

Computer::Computer(std::string computerManufacturer, std::string computerOS) : 
manufacturer(computerManufacturer),
operatingSystem(computerOS),
amountOfRam(8)
{
    std::cout << "CONSTRUCTING Computer: " << manufacturer << " - running " << operatingSystem << std::endl;
    logicPro.start();
}

Computer::~Computer()
{
    std::cout << "DESTRUCTING Computer" << std::endl;
    logicPro.close();
    shutDown();
}

void Computer::runProgram(std::string program, int priority)
{
    std::cout << "Running " << program << " with priority " << priority << std::endl;
}

void Computer::shutDown()
{
    std::cout << "Computer " << manufacturer << " shut down!" << std::endl;
}

void Computer::eraseDisk(std::string volumeName)
{
    std::cout << "Erased Disk " << volumeName << std::endl;
}

void Computer::showInfo()
{
    std::cout << "The Computer has " << amountOfRam << "GB of RAM and a processor speed of " << processorSpeed << " GHz" << std::endl;
}

void Computer::powerOffCountdown() 
{
    int i = 10;
    while (i > 0)
    {
        std::cout << "Power off in " << i << std::endl;
        --i;
    }
    shutDown();
} 

void Computer::Application::start()
{
    std::cout << name << " started" << std::endl;
}

void Computer::Application::close()
{
    std::cout << name << " closed" << std::endl;
}

void Computer::Application::install(std::string filePath)
{
    std::cout << name << " installed on " << filePath << std::endl;
}

void Computer::Application::printThisApplicationSize()
{
    std::cout << "This " << this->name << " by " << this->manufacturer << " has a size of " << this->size << " GB" << std::endl;
}

