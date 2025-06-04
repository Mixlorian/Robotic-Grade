#include "House.h"
#include <iostream>

using namespace std;

namespace C3{

    House::House(){
        cout << "A house has been created" << endl;
    }
    House::~House(){
        cout << "A house has been destroyed" << endl;
    }
    void House::paint(string color){
        cout << "The house is painted of" << color << endl;
    }

}