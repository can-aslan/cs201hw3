// Yağız Can Aslan 22001943 CS201-3

#include "Flower.h"
#include <string>
using namespace std;

class FlowerList {
    public:
        FlowerList();
        FlowerList(const FlowerList& aList);
        ~FlowerList();
        bool isEmpty() const;
        int getLength() const;
        bool retrieve(string flowerName, Flower& flower) const;
        Flower* take( string flowerName) const;
        Flower* takeByIndex( int indexInLinkedList) const;
        bool add(string flowerName);
        bool remove(string flowerName);
        bool doesFlowerExist(string flowerName);
        bool doesFlowerExistConst(string flowerName) const;
        void printFlowers() const;
    private:
        struct FlowerNode{
            Flower f;
            FlowerNode* next;
        };
        int size;
        FlowerNode* head; // the flowers are stored in a sorted singly linear linked list
        // ...
        // you may define additional member functions and data members, if necessary
};
