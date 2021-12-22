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
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

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

bool FlowerList::doesFlowerExistConst(string flowerName) const {
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    if ( size < 1 ) {
        return false;
    }
    
    FlowerNode* current = head;

    for ( int i = 0; i < size; i++ ) {
        if ( current->f.getName() == flowerName ) {
            return true;
        }
        else if ( current->next != NULL ) {
            current = current->next;
        }
        else {
            return false;
        }
    }

    return false;
}

bool FlowerList::add( string flowerName) { // Check "Flower List not empty" case later
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower); // Change flowerName to all lowercase

    if ( doesFlowerExist( flowerName) ) {
        return false;
    }

    if ( head == NULL ) { // If the Flower List is empty
        head = new FlowerNode();

        Flower* flwr = new Flower( flowerName);
        head->f = *flwr;
        delete flwr;

        head->next = NULL;

        size++;
        return true;
    }

    FlowerNode* temp = head;
    FlowerNode* prev = head;
    
    // If the Flower List is not empty
    while ( temp->f.getName() < flowerName ) {
        if ( temp->next != NULL ) {
            prev = temp;
            temp = temp->next;
        }
        else { // If there are no flowers left, add the feature to the end of the list
            FlowerNode* addThis = new FlowerNode();

            Flower* flwr = new Flower( flowerName);
            addThis->f = *flwr;
            delete flwr;

            addThis->next = NULL;
            temp->next = addThis;

            size++;
            return true;
        }
    }

    // If the algorithm reaches here, it means that the
    // alphabetical order is here for the desired flower
    FlowerNode* addThis = new FlowerNode();

    if ( temp->next != NULL || size == 1 ) {
        Flower* flwr = new Flower( flowerName);
        addThis->f = *flwr;
        delete flwr;

        if ( size == 1 ) {
            head->next = addThis;
            addThis->next = NULL;
        }
        else {
            FlowerNode* temporary = prev->next;
            prev->next = addThis;
            addThis->next = temporary;
        }
    }
    else { // If we are at the end of the list
        temp->next = new FlowerNode();

        Flower* flwr = new Flower( flowerName);
        temp->next->f = *flwr;
        delete flwr;

        temp->next->next = NULL;
    }
    
    size++;
    return true;
}

bool FlowerList::remove( string flowerName) {
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    if ( !doesFlowerExist( flowerName) ) {
        return false;
    }

    // If the feature size is 1
    if ( size == 1 ) {
        delete head;
        head = NULL;

        size--;
        return true;
    }

    // Check the first node
    if ( head->f.getName() == flowerName ) {
        FlowerNode* temp = head->next;
        delete head;
        head = temp;

        size--;
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
            return false;
        }
        else if ( current->f.getName() == flowerName ) {
            previous->next = current->next;
            delete current;
            
            size--;
            return true;
        }    
    }

    return false;
}

bool FlowerList::retrieve( string flowerName, Flower& flower) const {
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    if ( size < 1 || !doesFlowerExistConst( flowerName) ) {
        return false;
    }
    
    // Linear pass over the Linked List to see if the flower already exists (for simplicity)
    FlowerNode* checkFlower = head;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFlower->f.getName() != flowerName && checkFlower->next != NULL ) {
            checkFlower->f = checkFlower->next->f;
            checkFlower->next = checkFlower->next->next;
        }
        else if ( checkFlower->f.getName() == flowerName ) {
            flower = checkFlower->f;
            return true;
        }
    }

    return false;
}

void FlowerList::printFlowers() const {
    if ( size < 1 ) {
        cout << "No flowers in the library." << endl;
    }
    else {
        FlowerNode printer;
        printer.f = head->f;
        printer.next = head->next;
        
        for ( int i = 0; i < size; i++ ) {
            cout << printer.f.printFlower() << endl;
            if ( printer.next != NULL ) {
                printer.f = printer.next->f;
                printer.next = printer.next->next;
            }
        }
    }
}

Flower* FlowerList::take( string flowerName) { // Change return type to Flower* later and parameters to only string flowerName
    transform( flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    if ( size < 1 || !doesFlowerExistConst( flowerName) ) {
        return NULL;
    }
    
    // Linear pass over the Linked List to see if the flower already exists (for simplicity)
    FlowerNode* checkFlower = head;

    for ( int i = 0; i < size; i++ ) {
        if ( checkFlower->f.getName() != flowerName && checkFlower != NULL ) {
            //checkFlower->f = checkFlower->next->f;
            checkFlower = checkFlower->next;
        }
        else if ( checkFlower->f.getName() == flowerName ) {
            return &(checkFlower->f);
        }
    }

    return NULL;
}

Flower* FlowerList::takeByIndex( int indexInLinkedList) const {
    if ( size < 1 || indexInLinkedList > size ) {
        return NULL;
    }
    
    // Linear pass over the Linked List to see if the flower already exists (for simplicity)
    FlowerNode* checkFlower = head;

    for ( int i = 0; i < indexInLinkedList + 1; i++ ) {
        if ( i == indexInLinkedList ) {
            return &(checkFlower->f);
        }
        else if ( checkFlower != NULL ) {
            //checkFlower->f = checkFlower->next->f;
            checkFlower = checkFlower->next;
        }
        else {
            return NULL;
        }
    }

    return NULL;
}