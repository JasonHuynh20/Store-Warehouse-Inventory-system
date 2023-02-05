
#include "Store.h"

//constructor
Store::Store(const string& name){
    this->name = name;
    products = new List();
}

//destructor
Store::~Store(){
    delete products;
}

//find the first available store
void Store::findAvailableSLoc(StoreLocation** sloc){
    for(int i = 0; i < SLOCS; i++){
        if(storeList[i].isAvailable()){
            *sloc = &storeList[i];
            return;
        }
    }
}

//find the first warehouse
void Store::findAvailableWHLoc(WHLocation** wloc){
    for(int i = 0; i < WHLOCS; i++){
        if(whList[i].isAvailable()){
            *wloc = &whList[i];
            return;
        }
    }
    std::cout<<"nolocations" << std::endl;
}


void Store::findProduct(const string& name, Product** prod){

    products->findProduct(name, prod);

}

//if available print the store
const void Store::printStoreStock(){
    for(int i = 0; i < SLOCS; i++){
        if(!storeList[i].isAvailable()){
            storeList[i].print();
        }
    }
}

//loop and print non empty warehouse
const void Store::printWareHouseStock(){
    for(int i = 0; i < WHLOCS; i++){
        if(whList[i].getQuantity() != 0){
            whList[i].print();
        }
    }
}

const void Store::printProducts(){
    products->print();
}

// add the products to store and over stock to warehouse
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);

        prod = new Product(pname, sloc);

        products->add(prod);


    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);

        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }

    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

//remove the quntity from the store
void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}
