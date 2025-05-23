/*
 * Copyright (C) 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "vehicle.h"
#include "gaspowered.h"
#include "car.h"

using namespace std;
using namespace C3;

int main(int argc, char *argv[])
{
  float      weight   = 800.0;
  uint8_t    nwheels  = 4;
  uint16_t   autonomy = 1000;
  float      capacity = 90.0;
  string     brand    = "Kia";
  CarPtr     cp1      = new Car(weight, nwheels, autonomy, capacity, brand);
  VehiclePtr v1       = cp1;

  cout << "V1\n--\nweight: \t" << v1->get_weight() << '\n';
  cout << "wheels: \t"         << static_cast<int>(v1->get_nwheels()) << '\n';
  cout << "autonomy: \t"       << v1->get_autonomy() << '\n';
  cout << "nspeed: \t"         << v1->get_speed() << '\n';


  v1->set_autonomy(673.0);
  v1->set_speed(93.3);
  cout << "·····················\nnew autonomy: \t"
       << v1->get_autonomy() << '\n';
  cout << "new speed: \t" << v1->get_speed() << "\n\n\n";
  GaspoweredPtr gp1 = dynamic_cast<GaspoweredPtr>(v1);
  gp1->set_capacity(456.0);
  gp1->set_brand("Citröen");
  cout << "Gp1\n---\nnew capacity: \t"
       << gp1->get_capacity() << '\n';
  cout << "new brand: \t" << gp1->get_brand() << "\n\n\n";

  delete gp1;
  
  CarPtr     cp2     = new Car(weight, nwheels, autonomy, capacity, brand);
  VehiclePtr v2    = cp2;


  GaspoweredPtr gp2 = dynamic_cast<GaspoweredPtr>(v2);
  gp2->set_capacity(58965.0);
  gp2->set_brand("Ferrari");
  cout << "Gp2\n---\nnew capacity: \t"
       << gp2->get_capacity() << '\n';
  cout << "new brand: \t" << gp2->get_brand() << "\n\n\n";

  delete gp2;



  return 0;
}
