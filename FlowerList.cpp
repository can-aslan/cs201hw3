// Yağız Can Aslan 22001943 CS201-3
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "FlowerList.h"
using namespace std;

/*
class FlowerList {
    public:
        + FlowerList();
        + FlowerList(const FlowerList& aList);
        + ~FlowerList();
        + bool isEmpty() const;
        + int getLength() const;
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

bool FlowerList::isEmpty() const {
    return size;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::doesFlowerExist(string flowerName) {
    if ( size < 1 ) {
        return false;
    }
    
    // Linear pass over the Linked List to see if the feature already exists (for simplicity)
    FlowerNode* checkFeature = new FlowerNode();
    checkFeature->f = head->f;
    checkFeature->next = checkFeature->next;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFeature->f != f && checkFeature->next != NULL ) {
            checkFeature->f = checkFeature->next->f;
            checkFeature->next = checkFeature->next->next;
        }
        else if ( checkFeature->f == f ) {
            delete checkFeature;
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

    FeatureNode* temp = head;

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
    
    // If the algorithm reaches here, it means that the
    // alphabetical order is here for the desired feature
    FeatureNode* tempNext = new FeatureNode();
    delete tempNext;

    if ( temp->next != NULL ) {
        tempNext->feature = temp->next->feature;
        tempNext->next = temp->next->next;

        delete temp->next;    
        temp->next = new FeatureNode();

        temp->next->feature = feature;
        temp->next->next = tempNext;
    }
    else { // If we are at the end of the list
        temp->next = new FeatureNode();
        temp->next->feature = feature;
        temp->next->next = NULL;
    }
    
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
        cout << feature << " is removed from " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return true;
    }

    // Check the first node
    if ( head->feature == feature ) {
        FeatureNode* temp = head->next;
        delete head;
        head = temp;

        size--;
        cout << feature << " is removed from " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
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
            cout << feature << " is removed from " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return true;
        }    
    }

    cout << feature << " does not exist in " << flowerName << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
    return false;
}