#include <iostream>
#include "bicycle.h"

using namespace std;

namespace C3{
            Bicycle::Bicycle(int m):Vehicle(m){
                
            }
            Bicycle::~Bicycle(){
                cout << "Bicycle destroyed" << endl;
            }
            void Bicycle::paint(string color){
                cout << "Painting (" << model << ") a bicycle on" << color << endl; 
            }
            void Bicycle::start(){
                cout << "Bicycle started";
            }
}