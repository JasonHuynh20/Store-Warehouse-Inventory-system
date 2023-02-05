#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "WHLocation.h"

class Queue{
  //subclass
    class Node{
        public:
            Node* next;
            WHLocation* data;
    };

    private:
        Node* head;
        Node* tail;

    public:
      //constructor/destructor
        Queue();
        ~Queue();

        //functions-----------
        const bool isEmpty();
        void peekFirst(WHLocation** stu);
        void popFirst(WHLocation** stu);
        void addLast(WHLocation* stu);
        const void print();



};
#endif
