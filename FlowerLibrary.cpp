// Yağız Can Aslan 22001943 CS201-3

#include <bits/stdc++.h>
#include "FlowerLibrary.h"
#include <string>
#include <iostream>
using namespace std;

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

    Flower* f = flowers.take( name);

    if ( !f ) {
        cout << name << " isn't found in the library" << endl;
    }
    else {
        cout << f->printFlower() << endl;
    }
}

void FlowerLibrary::addFeature(string name,string feature) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    if ( flowers.take( name) ) {
        flowers.take( name)->add( feature);
    }
    else {
        cout << name << " isn't found in the library" << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    transform( name.begin(), name.end(), name.begin(), ::tolower);

    if ( flowers.take( name) ) {
        flowers.take( name)->remove( feature);
    }
    else {
        cout << name << " isn't found in the library" << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const {
    transform( feature.begin(), feature.end(), feature.begin(), ::tolower);

    int flowersFound = 0;
    Flower* f;
    cout << feature << " flowers: ";

    for ( int i = 0; i < flowers.getLength(); i++ ) {
        f = flowers.takeByIndex( i);
        if ( f != NULL ) {
            if ( f->doesFeatureExist( feature) ) {
                if ( !flowersFound ) {
                    cout << f->getName();
                }
                else {
                    cout << ", " << f->getName();
                }

                flowersFound++;
            }
        }
    }

    if ( !flowersFound ) {
        cout << "there is no such flower" << endl;
    }
    else {
        cout << endl;
    }    
}