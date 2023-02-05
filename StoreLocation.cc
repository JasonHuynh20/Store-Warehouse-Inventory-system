#include <iostream>
#include "StoreLocation.h"

 const char StoreLocation::code = 'A';
 const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 1;


//constructor
StoreLocation::StoreLocation():Location(code, nextId++){
}


//setter
void StoreLocation::setProduct(std::string pro){
    product = pro;
}


//ogetters
const int StoreLocation::getFreeSpace(){
    int diff = capacity - quantity;
    return diff;
}

const int StoreLocation::getCapacity(){
    return capacity;
}



bool StoreLocation::add(const std::string& pro, int quant){
    //if there are no products, set it
    if(product == "Empty" && quant <= capacity){
        product = pro;
        quantity = quant;
        return true;
    }
    //if there is product, add more up to limit
    if(product == pro){
        if((capacity - quantity) >= quant){
            quantity += quant;
            return true;
        }
    }
    return false;

}

//subtract the amount specified
bool StoreLocation::remove(int quant){
    if(quant <= capacity){
        quantity -= quant;
        return true;
    }
    return false;
}
