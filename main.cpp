/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

/*
 copied UDT 1:
 */
#include <iostream>

struct ElectricGuitar
{
    ElectricGuitar();
    ~ElectricGuitar();

    int numberOfStrings = 6;
    int numberOfPickups = 2;
    std::string color = "blue";
    std::string name;
    float price;    

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

    void plugIn(std::string cableColor);
    void selectPickup(int pickup);
    void changeVolume(float volume);
    void turnUpVolume();

    GuitarString string1; 
};

ElectricGuitar::ElectricGuitar() : name("Telecaster"), price(1899.99f) 
    { 
        std::cout << "CONSTRUCTING ElectricGuitar" << std::endl;
    }

ElectricGuitar::~ElectricGuitar()
    {
        std::cout << "DESTRUCTING ElectricGuitar" << std::endl;
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
    Computer();
    ~Computer();
    int amountOfRam;
    float processorSpeed {2.4f};
    int sizeOfDisk = 4;
    std::string manufacturer = "Apple";
    std::string operatingSystem = "MacOS";

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
    };

    void runProgram(std::string program, int priority);
    void shutDown();
    void eraseDisk(std::string volumeName);
    void showInfo();
    void powerOffCountdown();

    Application logicPro;
};

Computer::Computer() : amountOfRam(8)
{
    std::cout << "CONSTRUCTING Computer" << std::endl;
}

Computer::~Computer()
{
    std::cout << "DESTRUCTING Computer" << std::endl;
}

void Computer::runProgram(std::string program, int priority)
{
    std::cout << "Running " << program << " with priority " << priority << std::endl;
}

void Computer::shutDown()
{
    std::cout << "Computer shut down!" << std::endl;
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
// ============================================================

/*
 copied UDT 3:
 */

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
int main()
{
    ElectricGuitar telecaster;
    telecaster.plugIn("green");
    telecaster.selectPickup(1);
    telecaster.changeVolume(9.9f);
    telecaster.string1.breakString();
    telecaster.string1.tuneString(442.2f);
    telecaster.string1.pluckString(12);
    std::cout << "Price: " << telecaster.price << std::endl;
    std::cout << "String-Manufacturer: " << telecaster.string1.manufacturer << std::endl;
    telecaster.turnUpVolume();
    std::cout << "============================================================" << std::endl;

    Computer macbook;
    macbook.runProgram("Ableton", 10);
    macbook.shutDown();
    macbook.eraseDisk("Macintosh HD");
    macbook.logicPro.start();
    macbook.logicPro.close();
    macbook.logicPro.install("Macintosh HD");
    macbook.showInfo();
    std::cout << macbook.logicPro.name << " by " << macbook.logicPro.manufacturer << " has a size of " << macbook.logicPro.size << " GB" << std::endl;
    macbook.powerOffCountdown();
    std::cout << "============================================================" << std::endl;


    std::cout << "good to go!" << std::endl;
}
