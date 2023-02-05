#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List{

    //friend class Student;

    //private by default
    class Node {

        public:
            Product* data;
            Node*    next;
    };

    public:
        //constructors/destructors--------------------------------------------
        List();
        ~List();

        //member functions-----------------------------------------
        void add(Product*);
        void get(const string& name, Product**); //return false if name not found

        void remove(const string& name, Product**);        //double pointer for a return parameter of a pointer

        void removeUpTo(const string& name);

        void print() const;  //not modify this List object

        const bool isEmpty();

        void findProduct(const string& name, Product** prod);


    private:
        Node* head;

};


#endif
