// Yağız Can Aslan 22001943 CS201-3

#include <bits/stdc++.h> // Ask TA if it is allowed!!!
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
        + bool add(string feature);
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

Flower::Flower( string flowerName) {
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower); // Change flowerName to all lowercase
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

Flower::Flower( const Flower& aFlower) {
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

bool Flower::add( string feature) { // Check "Feature List not empty" case later
    transform( feature.begin(), feature.end(), feature.begin(), ::tolower); // Change feature to all lowercase

    if ( head == NULL ) { // If the Feature List is empty
        head = new FeatureNode();
        head->feature = feature;
        head->next = NULL;

        return true;
    }

    FeatureNode* temp = new FeatureNode();
    temp = head;

    // If the Feature List is not empty
    while ( temp->feature < feature ) {
        if ( temp->next != NULL ) {
            temp = temp->next;
        }
        else { // If there are no features left, add the feature to the end of the list
            temp->next = new FeatureNode();
            temp->next->feature = feature;
            temp->next->next = NULL;

            return true;
        }
    }

    // If the algorithm reaches here, it means that there are still features in the list but
    // the alphabetical order is here for the desired feature
    FeatureNode* tempNext = temp->next;
    temp->next = new FeatureNode();
    temp->next->feature = feature;
    temp->next->next = tempNext;

    return true;
}