#ifndef STORELOCATION_H
#define STORELOCATION_H


#include <string>
#include "defs.h"
#include "Location.h"


class StoreLocation: public Location{
    private:
        static const char code;
        static const int capacity;
        static int nextId;





	public:
		//constructor
		StoreLocation();


		//setter
        void setProduct(std::string pro);


        //other
        const int getFreeSpace();

        const int getCapacity();
        bool add(const std::string& pro, int quant);
        bool remove(int quant);





};
#endif
