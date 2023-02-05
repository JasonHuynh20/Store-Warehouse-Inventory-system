
#ifndef LOCATION_H
#define LOCATION_H


#include <string>


class Location {
    protected:
        std::string id;
        std::string product;
        int quantity;
        static const std::string NONE;



	public:
		//constructor
		Location(char A, int B);

		//destructor
		virtual ~Location();

		//getter
        const std::string& getId();
        const std::string& getProduct();
        const int getQuantity();

        //other
        const bool isEmpty();
        const bool isAvailable();
        const void print();

        virtual const int getCapacity() = 0;
        virtual bool add(const std::string& product, int quantity) = 0;
        virtual bool remove(int quantity) = 0;





};
#endif
