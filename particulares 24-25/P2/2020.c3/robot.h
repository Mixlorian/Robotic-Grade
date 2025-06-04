/* -*- mode: C++ -*-
 * Copyright (C) 2020
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

#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>

#include "macros.h"
#include "noisesensor.h"

namespace C3 {
class Robot
  {
  public:
    Robot(const std::string name);
    virtual ~Robot();

// los metodos que no son virtuales solo se implementan en la clase base
    std::string get_name ();
    void add_sensor (NoiseSensorPtr aSensor);
    NoiseSensorPtr get_sensor(uint s);  // Devuelve el sensor en la
                                        // posicion 's'

// metodo que tiene aqui implementacion pero tiene pinta de que se sobrescibira
// en las derivadas
    virtual uint get_num_sensors();

// metodo de clase
    static uint get_total_robots_created ();

// se implementan en las clases derivadas, porque son virtuales puros
    virtual bool canWalk () = 0;
    virtual bool canTalk () = 0;

  private:
// variables de instancia
    std::string theName;
    std::vector<NoiseSensorPtr> theSensors;
	// std::vector<NoiseSensor *> theSensors;

// variable global a la clase o variable de clase
    static uint totalRobotsCreated;
  };

  DECLARE_PTR(Robot); // RobotPtr
}  // C3

#endif /* ROBOT_H */
