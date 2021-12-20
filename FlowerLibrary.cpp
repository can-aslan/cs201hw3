// Yağız Can Aslan 22001943 CS201-3

#include <bits/stdc++.h>
#include "FlowerLibrary.h"
#include <string>
#include <iostream>
using namespace std;

/*class FlowerLibrary {
    public:
        + FlowerLibrary();
        + ~FlowerLibrary();
        - void addFlower(string name);
        - void removeFlower(string name);
        - void listFlowers() const;
        - void listFeatures(string name) const;
        - void addFeature(string name,string feature);
        - void removeFeature(string name, string feature);
        - void findFlowers(string feature) const;
    private:
        FlowerList flowers;
        // ...
        // you may define additional member functions and data members, if necessary
};*/

FlowerLibrary::FlowerLibrary() {
    FlowerList flowers;
}

FlowerLibrary::~FlowerLibrary() {}

void FlowerLibrary::addFlower(string name) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    if ( flowers.add( name) ) {
        cout << name << " has been added into the library." << endl;
    }
    else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    if ( flowers.remove( name) ) {
        cout << name << " has been removed from the library." << endl;
    }
    else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    flowers.printFlowers();
}

void FlowerLibrary::listFeatures(string name) const {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    Flower f;

    if ( !flowers.retrieve(name, f) ) {
        cout << name << " isn't found in the library" << endl;
    }
    else {
        cout << f.printFlower() << endl;
    }
}

void FlowerLibrary::addFeature(string name,string feature) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    Flower* f;

    if ( flowers.take( name) != NULL ) {
        flowers.take( name)->add( feature);
    }
    else {
        cout << name << " isn't found in the library" << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    Flower* f;

    if ( flowers.take( name) != NULL ) {
        flowers.take( name)->remove( feature);
    }
    else {
        cout << name << " isn't found in the library" << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const {
    transform( feature.begin(), feature.end(), feature.begin(), ::tolower);

    int flowersFound = 0;
    Flower* f = flowers.takeByIndex( 0);
    cout << feature << " flowers: ";

    for ( int i = 0; i < flowers.getLength(); i++ ) {
        f = flowers.takeByIndex( i);
        if ( f != NULL ) {
            if ( f->doesFeatureExist( feature) ) {
                flowersFound++;
                cout << f->getName() << ", ";
            }
        }
    }

    if ( !flowersFound ) {
        cout << "there is no such flower" << endl;
    }

    /*FlowerList flowersCopy = flowers;
    FlowerList flowersToPrint = flowers;
    
    int size = flowersCopy.getLength();
    int sizeToPrint = flowersCopy.getLength();
    Flower* f;

    for ( int i = 0; i < size; i++ ) { // Linear pass over the copy Flower List to find desired flowers
        if ( flowersCopy.takeByIndex( i, f) ) {
            if ( !(f->doesFeatureExist( feature)) ) {
                flowersToPrint.remove( f->getName());
                sizeToPrint--;
            }
        }
    }

    if ( sizeToPrint == 0 ) {
        cout << feature << " flowers: there is no such flower" << endl;
    }
    else {
        cout << feature << " flowers: ";

        Flower* toPrint;
        for ( int i = 0; i < sizeToPrint - 1; i++ ) { // Linear pass over the to-be-printed Flower List to find desired flowers
            flowersToPrint.takeByIndex( i, toPrint);
            cout << toPrint->getName() << ", ";
        }

        flowersToPrint.takeByIndex( (sizeToPrint - 1), toPrint);
        cout << toPrint->getName() << endl;
    }*/
    
}