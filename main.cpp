/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */


/*
 copied UDT 1:
 */
#include <iostream>
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

struct ElectricGuitarWrapper
{
    ElectricGuitarWrapper(ElectricGuitar* ptr) : pointerToElectricGuitar(ptr) { }
    ~ElectricGuitarWrapper()
    {
        delete pointerToElectricGuitar;
    }
    ElectricGuitar* pointerToElectricGuitar = nullptr;
};

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

// ============================================================
/*
 copied UDT 2:
 */

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

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr) : pointerToComputer(ptr) { }
    ~ComputerWrapper()
    {
        delete pointerToComputer;
    }
    Computer* pointerToComputer = nullptr;
};

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
// ============================================================

/*
 copied UDT 3:
 */
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

struct BusWrapper
{
    BusWrapper(Bus* ptr) : pointerToBus(ptr) { }
    ~BusWrapper()
    {
        delete pointerToBus;
    }
    Bus* pointerToBus = nullptr;
};

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
// ============================================================

/*
 new UDT 4:
 with 2 member functions
 */
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

struct MusicStoreWrapper
{
    MusicStoreWrapper(MusicStore* ptr) : pointerToMusicStore(ptr) { }
    ~MusicStoreWrapper()
    {
        delete pointerToMusicStore;
    }
    MusicStore* pointerToMusicStore = nullptr;
};

MusicStore::MusicStore()
{
    std::cout << "CONSTRUCTING Music Store" << std::endl;
}

MusicStore::~MusicStore()
{
    std::cout << "DESTRUCTING Music Store" << std::endl;
}

float MusicStore::valueOfGuitars() 
{
    return lesPaul.price + stratocaster.price;
}

float MusicStore::calculateBlackFridayPrice(int discount, float originalPrice)
{
    std::cout << "Huge Black Friday Discount!! Get " << discount << " percent of!! Old Price: $" << originalPrice << " New Price: $";
    return originalPrice * ( 100 - discount ) * 0.01f ;
}

void MusicStore::printThisGuitarValue()
{
    std::cout << "This value of the Guitars is $" << this->valueOfGuitars() << std::endl;
}

void MusicStore::printThisBlackFidayPrice(int discount, float originalPrice)
{
    std::cout << "This " << this->calculateBlackFridayPrice(discount, originalPrice) << std::endl;
}

void MusicStore::printThisLesPaulBlackFridayPrice(int discount)
{
    std::cout << "This Les Paul " << this->calculateBlackFridayPrice(discount, this->lesPaul.price) << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */

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

struct RentalServiceWrapper
{
    RentalServiceWrapper(RentalService* ptr) : pointerToRentalService(ptr) { }
    ~RentalServiceWrapper()
    {
        delete pointerToRentalService;
    }
    RentalService* pointerToRentalService = nullptr;
};

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
