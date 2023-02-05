
#include "Queue.h"

#include <iostream>


//constructor
Queue:: Queue(){
    head = NULL;
    tail = NULL;
}

//destructor
Queue::~Queue(){
    while(head != NULL){
        delete head;
        head = head->next;
    }
}

//functions--------------------------------
const bool Queue::isEmpty(){
    return (head == NULL);
}

void Queue::peekFirst(WHLocation** stu){
    *stu = head->data;
}

void Queue::popFirst(WHLocation** stu){
    *stu = head->data;
    Node* p = head;
    head = head->next;
    delete p;
}

void Queue::addLast(WHLocation* stu){
    Node* newNode = new Node;
    newNode->data = stu;
    newNode->next = NULL;
    tail = newNode;

    //if the list is empty
    if(head == NULL){
        head = newNode;
        return;
    }else{
      //find the last location and set
        Node* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}



const void Queue:: print(){
  while(head != NULL){
    head->data->print();
    head = head->next;
  }
}
