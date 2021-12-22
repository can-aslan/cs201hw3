// Yağız Can Aslan 22001943 CS201-3

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "Flower.h"
using namespace std;

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

Flower::Flower( const Flower& aFlower) { // Deep copy
    flowerName = aFlower.flowerName;
    size = aFlower.size;

    if ( size > 1 ) {
        head = new FeatureNode();
        head->feature = aFlower.head->feature;
           
        FeatureNode* current;
        FeatureNode* currentAFlower;

        current = head;
        currentAFlower = aFlower.head;

        for ( int i = 0; i < (size - 1); i++ ) {
            current->next = new FeatureNode();
            current->next->feature = currentAFlower->next->feature;

            if ( currentAFlower->next != NULL ) {
                currentAFlower = currentAFlower->next;
            }

            current = current->next;
        }
        
        current = NULL;
    }
    else if ( size == 1 ) {
        head = new FeatureNode();
        head->feature = aFlower.head->feature;
        head->next = NULL;
    }
    else { // If size < 1, in other words, if the list is empty
        head = NULL;
    }
}

Flower::~Flower() {
    if ( size == 1 ) {
        delete head;
    }
    else if ( size > 1 ) {
        while ( head != NULL ) {
            FeatureNode* temp = head->next;
            delete head;
            head = temp;
        }
    }
}

string Flower::getName() const {
    return flowerName;
}

bool Flower::isEmpty() const {
    return size;
}

int Flower::getLength() const {
    return size;
}

bool Flower::doesFeatureExist(string feature) {
    if ( size < 1 ) {
        return false;
    }
    
    // Linear pass over the Linked List to see if the feature already exists (for simplicity)
    FeatureNode* checkFeature = head;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFeature->feature != feature && checkFeature != NULL ) {
            checkFeature = checkFeature->next;
        }
        else if ( checkFeature->feature == feature ) {
            return true;
        }
    }

    return false;
}

bool Flower::add( string feature) { // Check "Feature List not empty" case later
    transform( feature.begin(), feature.end(), feature.begin(), ::tolower); // Change feature to all lowercase

    if ( doesFeatureExist( feature) ) {
        cout << feature << " already exists in " << flowerName << endl;
        return false;
    }

    if ( head == NULL ) { // If the Feature List is empty
        head = new FeatureNode();
        head->feature = feature;
        head->next = NULL;

        size++;
        cout << feature << " is added to " << flowerName << endl;
        return true;
    }

    FeatureNode* temp = head;
    FeatureNode* prev = head;

    // If the Feature List is not empty
    while ( temp->feature < feature ) {
        if ( temp->next != NULL ) {
            prev = temp;
            temp = temp->next;
        }
        else { // If there are no features left, add the feature to the end of the list
            temp->next = new FeatureNode();
            temp->next->feature = feature;
            temp->next->next = NULL;

            size++;
            cout << feature << " is added to " << flowerName << endl;
            return true;
        }
    }
    
    // If the algorithm reaches here, it means that the
    // alphabetical order is here for the desired feature
    if ( temp->next != NULL || size == 1 ) {
        FeatureNode* addThis = new FeatureNode();

        addThis->feature = feature;
        addThis->next = temp;

        if ( size == 1 ) {
            head = addThis;
        }
        else {
            prev->next = addThis;
        }
    }
    else { // If we are at the end of the list
        temp->next = new FeatureNode();
        temp->next->feature = feature;
        temp->next->next = NULL;
    }
    
    size++;
    cout << feature << " is added to " << flowerName << endl;
    return true;
}

bool Flower::remove( string feature) {
    if ( !doesFeatureExist( feature) ) {
        cout << feature << " does not exist in " << flowerName << endl;
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
    FeatureNode* current = head->next;
    FeatureNode* previous = head;

    for ( int i = 0; i < size - 1; i++ ) {
        if ( current->feature != feature && current != NULL ) {
            previous = current;
            current = current->next;
        }
        else if ( current->feature != feature && current->next == NULL ) {
            cout << feature << " does not exist in " << flowerName << endl;
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

    cout << feature << " does not exist in " << flowerName << endl;
    return false;
}

string Flower::printFlower() const {
    if ( size < 1 ) {
        return flowerName + ": No feature";
    }
    else {
        string flowerPrint;
        flowerPrint = flowerName + ": ";
        
        FeatureNode* printer = head;
        
        for ( int i = 0; i < (size - 1); i++ ) {
            flowerPrint = flowerPrint + printer->feature + ", ";
            printer = printer->next;
        }

        flowerPrint = flowerPrint + printer->feature;
        return flowerPrint;
    }
}

Flower& Flower::operator=( const Flower& right) { // Deep copy
    flowerName = right.flowerName;
    size = right.size;

    if ( size > 1 ) {
        head = new FeatureNode();
        head->feature = right.head->feature;
           
        FeatureNode* current = head;
        FeatureNode* currentAFlower = right.head;

        for ( int i = 0; i < (size - 1); i++ ) {
            current->next = new FeatureNode();
            current->next->feature = currentAFlower->next->feature;

            if ( currentAFlower->next != NULL ) {
                currentAFlower = currentAFlower->next;
            }

            current = current->next;
        }
        
        current = NULL;
    }
    else if ( size == 1 ) {
        head = new FeatureNode();
        head->feature = right.head->feature;
        head->next = NULL;
    }
    else { // If size < 1, in other words, if the list is empty
        head = NULL;
    }
    
    return *this;
}