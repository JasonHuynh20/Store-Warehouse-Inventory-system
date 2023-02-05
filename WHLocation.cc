#include "WHLocation.h"
#include <iostream>

    const char WHLocation::code = 'B';
    const int WHLocation::capacity = WHLOC_CAPACITY;
    int WHLocation::nextId = 1;

//constructor
WHLocation::WHLocation():Location(code, nextId++){

}


//other
const int WHLocation::getCapacity(){

    return capacity;
}

//add tp warehpouse if available and does not exceed capacity
bool WHLocation::add(const std::string& pro, int quant){
    if(isAvailable() && ((quantity + quant) <= capacity)){
        product = pro;
        quantity = quant;
        return true;
    }
    return false;

}

//remove quantity from warehouse
bool WHLocation::remove(int quant){
    if(quant <= capacity){
        quantity -= quant;
        if(quantity == 0){
            product = NONE;
        }
        return true;
    }
    return false;
}
