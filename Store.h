
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"


using namespace std;

class Store {

	public:
		//constructor
		Store(const string& name);

		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation**);
		void findAvailableWHLoc(WHLocation**);
		void findProduct(const std::string&, Product**);

		const void printStoreStock();
		const void printWareHouseStock();
		const void printProducts();

		//these are done for you

		void receiveProduct(const string&, int quantity);
		void fillOrder(const string&, int &quantity);
		void print();

	private:
		string name;
		StoreLocation storeList[SLOCS];
		WHLocation whList[WHLOCS];
		List* products;



};
#endif
