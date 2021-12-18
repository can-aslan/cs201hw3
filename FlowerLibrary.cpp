// Yağız Can Aslan 22001943 CS201-3

#include "FlowerLibrary.h"
#include "FlowerList.h"
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
    if ( flowers.add( name) ) {
        cout << name << " has been added into the library." << endl;
    }
    else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    if ( flowers.remove( name) ) {
        cout << name << "  has been removed from the library." << endl;
    }
    else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    flowers.printFlowers();
}

void FlowerLibrary::listFeatures(string name) const {
    if ( !flowers.doesFlowerExistConst( name) ) {
        
    }
}

void FlowerLibrary::addFeature(string name,string feature) {

}

void FlowerLibrary::removeFeature(string name, string feature) {

}

void FlowerLibrary::findFlowers(string feature) const {

}