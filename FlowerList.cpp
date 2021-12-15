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

FlowerList::FlowerList( const FlowerList& aList) { // Deep copy
    size = aList.size;
    
    for ( int i = 0; i < size; i++ ) {
        FlowerNode* addThis = new FlowerNode();
        
    }
}