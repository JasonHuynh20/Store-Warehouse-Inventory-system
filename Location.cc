
#include "Location.h"
#include <iostream>

const std::string Location::NONE = "Empty";

//constructor
Location::Location(char A, int B) : id(A + std::to_string(B)){
  product = NONE;
  quantity = 0;
}

//destructor
Location::~Location(){

}

//getter------------------------------------------------------------------------
const std::string& Location::getId(){
    return id;
}

const std::string& Location::getProduct(){
    return product;
}

const int Location::getQuantity(){
    return quantity;
}



//other------------------------------------------------------------------------
const bool Location::isEmpty(){
    return quantity == 0;
}

const bool Location::isAvailable(){
    return product == NONE;
}

const void Location::print(){
    std::cout << "ID: " << id << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
}
