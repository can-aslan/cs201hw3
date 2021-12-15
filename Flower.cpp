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
        + ~Flower();
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

bool Flower::doesFeatureExist(string feature) {
    // Linear pass over the Linked List to see if the feature already exists (for simplicity)
    FeatureNode* checkFeature = new FeatureNode();
    checkFeature->feature = head->feature;
    checkFeature->next = checkFeature->next;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFeature->feature != feature && checkFeature->next != NULL ) {
            checkFeature->feature = checkFeature->next->feature;
            checkFeature->next = checkFeature->next->next;
        }
        else if ( checkFeature->feature == feature ) {
            return true;
        }
    }

    delete checkFeature;
    return false;
}

bool Flower::add( string feature) { // Check "Feature List not empty" case later
    transform( feature.begin(), feature.end(), feature.begin(), ::tolower); // Change feature to all lowercase

    if ( doesFeatureExist( feature) ) {
        cout << feature << " already exists in " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return false;
    }

    if ( head == NULL ) { // If the Feature List is empty
        head = new FeatureNode();
        head->feature = feature;
        head->next = NULL;

        size++;
        cout << feature << " is added to " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
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

            size++;
            cout << feature << " is added to " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return true;
        }
    }

    // If the algorithm reaches here, it means that there are still features in the list but
    // the alphabetical order is here for the desired feature
    FeatureNode* tempNext = new FeatureNode();
    tempNext->feature = temp->next->feature;
    tempNext->next = temp->next->next;

    delete temp->next;
    temp->next = new FeatureNode();

    temp->next->feature = feature;
    temp->next->next = tempNext;

    size++;
    cout << feature << " is added to " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
    return true;
}

bool Flower::remove( string feature) {
    if ( !doesFeatureExist( feature) ) {
        cout << feature << " does not exist in " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return false;
    }

    // If the feature size is 1
    if ( size == 1 ) {
        delete head;
        head = NULL;

        size--;
        cout << feature << " is removed from " << flowerName << endl;
        return true;
    }

    // Check the first node
    if ( head->feature == feature ) {
        FeatureNode* temp = head->next;
        delete head;
        head = temp;

        size--;
        cout << feature << " is removed from " << flowerName << endl;
        return true;
    }

    // Make a linear pass over the feature list to find the desired feature to remove
    FeatureNode* current = new FeatureNode();
    FeatureNode* previous = new FeatureNode();

    previous->feature = head->feature;
    previous->next = head->next;
    current->feature = head->next->feature;
    current->next = head->next->next;

    for ( int i = 0; i < size - 1; i++ ) {
        if ( current->feature != feature && current->next != NULL ) {
            previous->feature = current->feature;
            previous->next = current->next;
            
            current->feature = current->next->feature;
            current->next = current->next->next;
        }
        else if ( current->feature != feature && current->next == NULL ) {
            cout << feature << " does not exist in " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return false;
        }
        else if ( current->feature == feature ) {
            previous->next = current->next;
            delete current;
            
            size--;
            cout << feature << " is removed from " << flowerName << endl;
            return true;
        }    
    }
}