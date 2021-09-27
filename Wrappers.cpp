#include "Wrappers.h"

#include "Computer.h"
#include "Bus.h"
#include "MusicStore.h"
#include "RentalService.h"

// Computer
ComputerWrapper::ComputerWrapper(Computer* ptr) : pointerToComputer(ptr) { }
ComputerWrapper::~ComputerWrapper()
{
    delete pointerToComputer;
}

// Bus
BusWrapper::BusWrapper(Bus* ptr) : pointerToBus(ptr) { }
BusWrapper::~BusWrapper()
{
    delete pointerToBus;
}

// MusicStore
MusicStoreWrapper::MusicStoreWrapper(MusicStore* ptr) : 
pointerToMusicStore(ptr) 
{}

MusicStoreWrapper::~MusicStoreWrapper()
{
    delete pointerToMusicStore;
}


// RentalService
RentalServiceWrapper::RentalServiceWrapper(RentalService* ptr) : 
pointerToRentalService(ptr) 
{}

RentalServiceWrapper::~RentalServiceWrapper()
{
    delete pointerToRentalService;
}




