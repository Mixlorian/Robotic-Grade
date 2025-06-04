#include <iostream>
#include "Vehicle.h"
#include "Paintable.h"

using namespace std;
namespace C3
{
    Vehicle::Vehicle(int m){
        model = m;
    }
    Vehicle::~Vehicle(){
        cout << "vehicle destroyed" << endl;
    }
    int Vehicle::getModel() const{
        return model;
    }
} // namespace C3
