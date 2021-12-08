// Yağız Can Aslan 22001943 CS201-3

#include <iostream>
#include <string>
#include "Flower.h"
using namespace std;

/*
public:
        + Flower();
        + Flower(string flowerName);
        + Flower(const Flower& aFlower);
        / ~Flower();
        + bool isEmpty() const;
        + int getLength() const ;
        x bool add(string feature);
        x bool remove(string feature);
        x string printFlower() const;
    private:
        struct FeatureNode{
            string feature;
            FeatureNode* next;
        };
        int size;
        string flowerName;
        FeatureNode *head; // the features are stored in a sorted singly linear linked list
*/

Flower::Flower() {
    flowerName = "";
    size = 0;
    head = NULL;
}

Flower::Flower(string flowerName) {
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

Flower::Flower(const Flower& aFlower) {
    flowerName = aFlower.flowerName;
    size = aFlower.size;
    *head = *aFlower.head;
}

Flower::~Flower() {
    while ( head->next != NULL ) {
        FeatureNode* temp = head->next;
        delete head;
        head = temp;
    }
}

bool Flower::isEmpty() const {
    return size;
}

int Flower::getLength() const {
    return size;
}