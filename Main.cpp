#include <iostream>
using namespace std;
//#include "FlowerLibrary.h" // UNCOMMENT LATER!!!!!!


#include "FlowerList.h" // REMOVE LATER!!!!!!!!!!!!!!

int main() {
    cout << "The test has begun." << endl;
    
    FlowerList list;
    list.printFlowers();

    list.add( "cornelius");
    list.printFlowers();

    list.add( "amogus");
    list.printFlowers();

    /*Flower* f = new Flower;
    if ( list.retrieve( "amogus", *f) ) {
        f->add( "impostor");
        list.printFlowers();
    }
    
    delete f;*/
    cout << "Test SUCCESSFULLY completed!" << endl;
    /*
    Flower* f = new Flower( "impostor");

    cout << f->printFlower() << endl;

    f->remove( "anxiety");
    cout << f->printFlower() << endl;

    f->add( "cornelius");
    cout << f->printFlower() << endl;

    f->add( "amogus");
    cout << f->printFlower() << endl;

    f->add( "amogus");
    cout << f->printFlower() << endl;

    f->remove( "dingding");
    cout << f->printFlower() << endl;

    f->remove( "vent");
    cout << f->printFlower() << endl;

    delete f;
    cout << endl;
    cout << "Test SUCCESSFULLY completed!" << endl;
    /*
    // empty
    Flower* fe = new Flower( "0");

    cout << "hi 1" << endl;
    Flower ff = *fe;
    cout << "hi 2" << endl;

    cout << fe->printFlower() << endl;
    cout << "hi 3" << endl;
    cout << ff.printFlower() << endl;
    cout << "hi 4" << endl;

    delete fe;
    cout << "hi 5" << endl;
    cout << ff.printFlower() << endl;
    
    cout << "hi 6" << endl;

    // single size
    Flower* fc = new Flower( "a");
    fc->add( "singl");

    cout << "hi 1" << endl;
    Flower fd = *fc;
    cout << "hi 2" << endl;

    cout << fc->printFlower() << endl;
    cout << "hi 3" << endl;
    cout << fd.printFlower() << endl;
    cout << "hi 4" << endl;

    delete fc;
    cout << "hi 5" << endl;
    cout << fd.printFlower() << endl;
    
    cout << "hi 6" << endl;

    // multi size
    Flower* fa = new Flower( "aaa");
    fa->add( "ft1");
    fa->add( "ft0");

    cout << "hi 1" << endl;
    Flower fb = *fa;
    cout << "hi 2" << endl;

    cout << fa->printFlower() << endl;
    cout << "hi 3" << endl;
    cout << fb.printFlower() << endl;
    cout << "hi 4" << endl;

    delete fa;
    cout << "hi 5" << endl;
    cout << fb.printFlower() << endl;
    
    cout << "hi 6" << endl;
    */
    /*
    FlowerLibrary L;
    L.listFlowers();

    // Testing add flower
    cout << "Testing add flower" << endl;
    cout << endl;

    L.addFlower("Magnolia");
    L.addFlower("SCARLET PIMPERNEL");
    L.addFlower("verbascum");
    cout << endl;

    L.addFlower("Magnolia");
    L.addFlower("magnolia");
    cout << endl;

    L.listFlowers();
    cout << endl;

    // Testing remove flower
    cout << endl;

    cout << "Testing remove flower" << endl;
    cout << endl;

    L.removeFlower("Magnolia");
    L.removeFlower("lantana");
    cout << endl;

    L.removeFlower("LANTANA");
    L.removeFlower("VERBASCUM");
    L.removeFlower("oleander");
    cout << endl;

    L.addFlower("verbascum");
    cout << endl;

    L.listFlowers();
    cout << endl;

    // Testing add feature
    cout << endl;

    cout << "Testing add feature" << endl;
    cout << endl;

    L.addFlower("calla lilly");
    cout << endl;

    L.listFeatures("magnolia");
    cout << endl;

    L.addFeature("verbascum", "yellow");
    L.addFeature("verbascum", "biennial");
    L.addFeature("verbascum", "Perennial");
    L.addFeature("calla lilly", "ornamental");
    cout << endl;

    L.addFeature("calla lilly", "ornamental");
    L.addFeature("Magnolia", "ornamental");
    cout << endl;

    L.addFlower("magnolia");
    L.addFeature("Magnolia", "ornamental");
    L.addFeature("Magnolia", "citronella scented");
    L.listFeatures("magnolia");
    cout << endl;

    L.listFeatures("calla lilly");
    cout << endl;

    // Testing remove feature
    cout << endl;

    cout << "Testing remove feature" << endl;
    cout << endl;

    L.removeFeature("magnolia", "citronella scented");
    L.removeFeature("magnolia", "yellow");
    L.listFeatures("magnolia");

    // Testing finding flowers
    cout << endl;

    cout << "Testing finding flowers" << endl;
    cout << endl;

    L.findFlowers("ornamental");
    L.findFlowers("yellow");
    cout << endl;

    L.findFlowers("white");
    cout << "Test successfully completed!";
    return 0;
    */
}