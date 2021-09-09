/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


/*
 copied UDT 1:
 */
#include <iostream>

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
    std::cout << "You have plugged the " << cableColor << " cable into the " << ElectricGuitar::color <<  " " << ElectricGuitar::name <<std::endl;
}

void ElectricGuitar::selectPickup(int pickup)
{
    std::cout << "Switched to pickup " << pickup << std::endl;
}

void ElectricGuitar::changeVolume(float volume)
{
    std::cout << "Changed volume of " << ElectricGuitar::name <<" to " << volume << std::endl;
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
    std::cout << "String " << ElectricGuitar::GuitarString::number << " just broke!! ";
    if (ElectricGuitar::GuitarString::isWound)
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
    std::cout << "String " << ElectricGuitar::GuitarString::number << " is tuned to " << referencePitch << " Hz" <<std::endl;
}

void ElectricGuitar::GuitarString::pluckString(int fret)
{
    std::cout << "Plucked String " << ElectricGuitar::GuitarString::number << " / fret " << fret << std::endl;
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
    std::cout << Computer::Application::name << " started" << std::endl;
}

void Computer::Application::close()
{
    std::cout << Computer::Application::name << " closed" << std::endl;
}

void Computer::Application::install(std::string filePath)
{
    std::cout << Computer::Application::name << " installed on " << filePath << std::endl;
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
    ElectricGuitar telecaster { "Fender", "Telecaster", 1899.99f };
    telecaster.plugIn("green");
    telecaster.selectPickup(1);
    telecaster.changeVolume(9.9f);
    telecaster.string1.breakString();
    telecaster.string1.tuneString(442.2f);
    telecaster.string1.pluckString(12);
    std::cout << "Price: " << telecaster.price << std::endl;
    telecaster.printThisPrice();
    std::cout << "String-Manufacturer: " << telecaster.string1.manufacturer << std::endl;
    telecaster.printThisStringManufacturer();
    telecaster.turnUpVolume();
    std::cout << "============================================================" << std::endl;

    Computer macbook { "Apple", "MacOs" };
    macbook.runProgram("Ableton", 10);
    macbook.shutDown();
    macbook.eraseDisk("Macintosh HD");
    macbook.logicPro.start();
    macbook.logicPro.close();
    macbook.logicPro.install("Macintosh HD");
    macbook.showInfo();
    std::cout << macbook.logicPro.name << " by " << macbook.logicPro.manufacturer << " has a size of " << macbook.logicPro.size << " GB" << std::endl;
    macbook.logicPro.printThisApplicationSize();
    macbook.powerOffCountdown();
    std::cout << "============================================================" << std::endl;

    Bus schoolBus;
    schoolBus.startEngine();
    schoolBus.turnLeft(30);
    schoolBus.openDoors(false);
    schoolBus.openDoors(true);
    std::cout << "The Bus made by " << schoolBus.manufacturer << " has " << schoolBus.numberOfSeats << " Seats and a maxiumum speed of " << schoolBus.maximumSpeed << " km/h" << std::endl;
    schoolBus.printThisBusInfo();
    schoolBus.drive(1500);
    std::cout << "============================================================" << std::endl;

    RentalService tourRentals;
    tourRentals.prepareComputer(); 
    tourRentals.goOnTour(250);
    std::cout << "============================================================" << std::endl;
    
    MusicStore guitarCenter;
    std::cout << "The value of the Guitars is $" << guitarCenter.valueOfGuitars() << std::endl;
    guitarCenter.printThisGuitarValue();
    std::cout << guitarCenter.calculateBlackFridayPrice(20, 1000.0f) << std::endl;
    guitarCenter.printThisBlackFidayPrice(20, 1000.0f);
    std::cout << guitarCenter.calculateBlackFridayPrice(10, guitarCenter.lesPaul.price) << std::endl;
    guitarCenter.printThisLesPaulBlackFridayPrice(10);
    std::cout << "============================================================" << std::endl;

    std::cout << "good to go!" << std::endl;
}
