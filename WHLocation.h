#ifndef WHLOCATION_H
#define WHLOCATION_H


#include <string>
#include "defs.h"
#include "Location.h"


class WHLocation: public Location{
    private:
        static const char code;
        static const int capacity;
        static int nextId;



	public:
		//constructor
		WHLocation();


        //other
        const int getCapacity();
        bool add(const std::string& pro, int quant);
        bool remove(int quant);





};
#endif
