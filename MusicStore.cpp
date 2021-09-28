#include <iostream>
#include "MusicStore.h"

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

