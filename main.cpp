/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


/*
 copied UDT 1:
 */
#include <iostream>
#include "LeakedObjectDetector.h"



// ============================================================
/*
 copied UDT 2:
 */



// ============================================================

/*
 copied UDT 3:
 */

// ============================================================

/*
 new UDT 4:
 with 2 member functions
 */


/*
 new UDT 5:
 with 2 member functions
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>

#include "ElectricGuitar.h"
#include "Computer.h"
#include "Bus.h"
#include "MusicStore.h"
#include "RentalService.h"

#include "Wrappers.h"

int main()
{
    ElectricGuitarWrapper telecaster( new ElectricGuitar("Fender", "Telecaster", 1899.99f) );
    telecaster.pointerToElectricGuitar->plugIn("green");
    telecaster.pointerToElectricGuitar->selectPickup(1);
    telecaster.pointerToElectricGuitar->changeVolume(9.9f);
    telecaster.pointerToElectricGuitar->string1.breakString();
    telecaster.pointerToElectricGuitar->string1.tuneString(442.2f);
    telecaster.pointerToElectricGuitar->string1.pluckString(12);
    std::cout << "Price: " << telecaster.pointerToElectricGuitar->price << std::endl;
    telecaster.pointerToElectricGuitar->printThisPrice();
    std::cout << "String-Manufacturer: " << telecaster.pointerToElectricGuitar->string1.manufacturer << std::endl;
    telecaster.pointerToElectricGuitar->printThisStringManufacturer();
    telecaster.pointerToElectricGuitar->turnUpVolume();
   
    std::cout << "============================================================" << std::endl;

    ComputerWrapper macbook ( new Computer ("Apple", "MacOs"));
    macbook.pointerToComputer->runProgram("Ableton", 10);
    
    macbook.pointerToComputer->shutDown();
    macbook.pointerToComputer->eraseDisk("Macintosh HD");
    macbook.pointerToComputer->logicPro.start();
    macbook.pointerToComputer->logicPro.close();
    macbook.pointerToComputer->logicPro.install("Macintosh HD");
    macbook.pointerToComputer->showInfo();
    std::cout << macbook.pointerToComputer->logicPro.name << " by " << macbook.pointerToComputer->logicPro.manufacturer << " has a size of " << macbook.pointerToComputer->logicPro.size << " GB" << std::endl;
    macbook.pointerToComputer->logicPro.printThisApplicationSize();
    macbook.pointerToComputer->powerOffCountdown();
    
    std::cout << "============================================================" << std::endl;

    BusWrapper schoolBus( new Bus() );
    schoolBus.pointerToBus->startEngine();
    schoolBus.pointerToBus->turnLeft(30);
    schoolBus.pointerToBus->openDoors(false);
    schoolBus.pointerToBus->openDoors(true);
    std::cout << "The Bus made by " << schoolBus.pointerToBus->manufacturer << " has " << schoolBus.pointerToBus->numberOfSeats << " Seats and a maxiumum speed of " << schoolBus.pointerToBus->maximumSpeed << " km/h" << std::endl;
    schoolBus.pointerToBus->printThisBusInfo();
    schoolBus.pointerToBus->drive(1500);
    std::cout << "============================================================" << std::endl;

    MusicStoreWrapper guitarCenter( new MusicStore() );
    std::cout << "The value of the Guitars is $" << guitarCenter.pointerToMusicStore->valueOfGuitars() << std::endl;
    guitarCenter.pointerToMusicStore->printThisGuitarValue();
    std::cout << guitarCenter.pointerToMusicStore->calculateBlackFridayPrice(20, 1000.0f) << std::endl;
    guitarCenter.pointerToMusicStore->printThisBlackFidayPrice(20, 1000.0f);
    std::cout << guitarCenter.pointerToMusicStore->calculateBlackFridayPrice(10, guitarCenter.pointerToMusicStore->lesPaul.price) << std::endl;
    guitarCenter.pointerToMusicStore->printThisLesPaulBlackFridayPrice(10);
    std::cout << "============================================================" << std::endl;

    RentalServiceWrapper tourRentals( new RentalService() );
    tourRentals.pointerToRentalService->prepareComputer(); 
    tourRentals.pointerToRentalService->goOnTour(250);
    std::cout << "============================================================" << std::endl;

    std::cout << "good to go!" << std::endl;
}
