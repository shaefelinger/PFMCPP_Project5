#pragma once

#include "Computer.h"
#include "Bus.h"
#include "MusicStore.h"
#include "RentalService.h"

struct Computer;
struct Bus;
struct MusicStore;
struct RentalService;


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

