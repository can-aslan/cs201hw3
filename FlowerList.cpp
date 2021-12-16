// Yağız Can Aslan 22001943 CS201-3
#include <iostream>
#include <string>
#include "FlowerList.h"
using namespace std;

/*
class FlowerList {
    public:
        FlowerList();
        FlowerList(const FlowerList& aList);
        ~FlowerList();
        bool isEmpty() const;
        int getLength() const;
        bool retrieve(string flowerName, Flower& flower) const;
        bool add(string flowerName);
        bool remove(string flowerName);
    private:
        struct FlowerNode{
            Flower f;
            FlowerNode* next;
        };
        int size;
        FlowerNode* head; // the flowers are stored in a sorted singly linear linked list
        // ...
        // you may define additional member functions and data members, if necessary
};*/

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::~FlowerList() {
    if ( size == 1 ) {
        delete head;
    }
    else if ( size > 1 ) {
        while ( head != NULL ) {
            FlowerNode* temp = head->next;
            delete head;
            head = temp;
        }
    }
}

FlowerList::FlowerList( const FlowerList& aList) { // Deep copy
    size = aList.size;

    if ( size > 1 ) {
        head = new FlowerNode();
        head->f = aList.head->f;
           
        FlowerNode* current;
        FlowerNode* currentAFlower;

        current = head;
        currentAFlower = aList.head;

        for ( int i = 0; i < (size - 1); i++ ) {
            current->next = new FlowerNode();
            current->next->f = currentAFlower->next->f;

            if ( currentAFlower->next != NULL ) {
                currentAFlower = currentAFlower->next;
            }

            current = current->next;
        }
        
        current = NULL;
    }
    else if ( size == 1 ) {
        head = new FlowerNode();
        head->f = aList.head->f;
        head->next = NULL;
    }
    else { // If size < 1, in other words, if the list is empty
        head = NULL;
    }
}