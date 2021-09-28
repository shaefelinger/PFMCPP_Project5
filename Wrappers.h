#pragma once

struct ElectricGuitar;
struct Computer;
struct Bus;
struct MusicStore;
struct RentalService;

// ElectricGuitar
struct ElectricGuitarWrapper
{
    ElectricGuitarWrapper(ElectricGuitar* ptr);
    ~ElectricGuitarWrapper();
 
    ElectricGuitar* pointerToElectricGuitar = nullptr;
};


// Computer
struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr);
    ~ComputerWrapper();
   
    Computer* pointerToComputer = nullptr;
};


// Bus
struct BusWrapper
{
    BusWrapper(Bus* ptr);
    ~BusWrapper();
 
    Bus* pointerToBus = nullptr;
};

// MusicStore
struct MusicStoreWrapper
{
    MusicStoreWrapper(MusicStore* ptr);
    ~MusicStoreWrapper();

    MusicStore* pointerToMusicStore = nullptr;
};

// RentalService
struct RentalServiceWrapper
{
    RentalServiceWrapper(RentalService* ptr);
    ~RentalServiceWrapper();
   
    RentalService* pointerToRentalService = nullptr;
};

