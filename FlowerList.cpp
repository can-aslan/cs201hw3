// Yağız Can Aslan 22001943 CS201-3
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "FlowerList.h"
using namespace std;

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
    
    // Linear pass over the Linked List to see if the flower already exists (for simplicity)
    FlowerNode* checkFlower = new FlowerNode();
    checkFlower->f = head->f;
    checkFlower->next = head->next;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFlower->f.getName() != flowerName && checkFlower->next != NULL ) {
            checkFlower->f = checkFlower->next->f;
            checkFlower->next = checkFlower->next->next;
        }
        else if ( checkFlower->f.getName() == flowerName ) {
            delete checkFlower;
            return true;
        }
    }

    delete checkFlower;
    return false;
}

bool FlowerList::add( string flowerName) { // Check "Feature List not empty" case later
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower); // Change flowerName to all lowercase

    if ( doesFlowerExist( flowerName) ) {
        cout << flowerName << " cannot be added into the library because it already exists." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return false;
    }

    if ( head == NULL ) { // If the Flower List is empty
        head = new FlowerNode();
        head->f = *(new Flower( flowerName));
        head->next = NULL;

        size++;
        cout << flowerName << " has been added into the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return true;
    }

    FlowerNode* temp = head;

    // If the Flower List is not empty
    while ( temp->f.getName() < flowerName ) {
        
        if ( temp->next != NULL ) {
            temp = temp->next;
        }
        else { // If there are no flowers left, add the feature to the end of the list
            temp->next = new FlowerNode();
            temp->next->f = *(new Flower( flowerName));
            temp->next->next = NULL;

            size++;
            cout << flowerName << " has been added into the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return true;
        }
    }
    
    // If the algorithm reaches here, it means that the
    // alphabetical order is here for the desired flower
    FlowerNode* tempNext = new FlowerNode();
    delete tempNext;

    if ( temp->next != NULL ) {
        tempNext->f = temp->next->f;
        tempNext->next = temp->next->next;

        delete temp->next;    
        temp->next = new FlowerNode();

        temp->next->f = *(new Flower( flowerName));
        temp->next->next = tempNext;
    }
    else { // If we are at the end of the list
        temp->next = new FlowerNode();
        temp->next->f = *(new Flower( flowerName));
        temp->next->next = NULL;
    }
    
    size++;
    cout << flowerName << " has been added into the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
    return true;
}

bool FlowerList::remove( string flowerName) {
    if ( !doesFlowerExist( flowerName) ) {
        cout << flowerName << " cannot be removed because it's not in the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return false;
    }

    // If the feature size is 1
    if ( size == 1 ) {
        delete head;
        head = NULL;

        size--;
        cout << flowerName << "  has been removed from the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return true;
    }

    // Check the first node
    if ( head->f.getName() == flowerName ) {
        FlowerNode* temp = head->next;
        delete head;
        head = temp;

        size--;
        cout << flowerName << "  has been removed from the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
        return true;
    }

    // Make a linear pass over the feature list to find the desired feature to remove
    FlowerNode* current = new FlowerNode();
    FlowerNode* previous = new FlowerNode();

    previous->f = head->f;
    previous->next = head->next;
    current->f = head->next->f;
    current->next = head->next->next;

    for ( int i = 0; i < size - 1; i++ ) {
        if ( current->f.getName() != flowerName && current->next != NULL ) {
            previous->f = current->f;
            previous->next = current->next;
            
            current->f = current->next->f;
            current->next = current->next->next;
        }
        else if ( current->f.getName() != flowerName && current->next == NULL ) {
            cout << flowerName << " cannot be removed because it's not in the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return false;
        }
        else if ( current->f.getName() == flowerName ) {
            previous->next = current->next;
            delete current;
            
            size--;
            cout << flowerName << "  has been removed from the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
            return true;
        }    
    }

    cout << flowerName << " cannot be removed because it's not in the library." << endl; // TODO: MOVE THE MESSAGE TO FLOWERLIBRARY LATER
    return false;
}

bool FlowerList::retrieve( string flowerName, Flower& flower) const {
    if ( size < 1 ) {
        return false;
    }

    // Linear pass over the Linked List to see if the flower already exists (for simplicity)
    FlowerNode* checkFlower = new FlowerNode();
    checkFlower->f = head->f;
    checkFlower->next = head->next;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFlower->f.getName() != flowerName && checkFlower->next != NULL ) {
            checkFlower->f = checkFlower->next->f;
            checkFlower->next = checkFlower->next->next;
        }
        else if ( checkFlower->f.getName() == flowerName ) {
            if ( &flower != NULL ) {
                delete &flower;
                flower = checkFlower->f;
            }
            else {
                flower = checkFlower->f;
            }
            return true;
        }
    }

    delete checkFlower;
    return false;
}

void FlowerList::printFlowers() {
    if ( size < 1 ) {
        cout << "No flowers in the library." << endl;
    }
    else {
        FlowerNode printer;
        printer.f = head->f;
        printer.next = head->next;
        
        for ( int i = 0; i < (size - 1); i++ ) {
            cout << printer.f.printFlower() << endl;
            printer.f = printer.next->f;
            printer.next = printer.next->next;
        }

        cout << printer.f.printFlower() << endl;
    }
}