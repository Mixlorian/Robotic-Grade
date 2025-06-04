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

#ifndef NOISESENSOR_H
#define NOISESENSOR_H

#include <string>

#include "sensor.h"
#include "macros.h"

namespace C3 {

  // era todo lo de sensor pero con el tipo T instanciado a float,
  // con lo cual no hereda de una clase generica, deja de ser generica.
  class NoiseSensor : public Sensor<float>{
  public:
    NoiseSensor(const std::string name);
    virtual ~NoiseSensor();
    void set_level (float l);
    float get_level ();
  };

  DECLARE_PTR(NoiseSensor);  // NoiseSensorPtr
}  // C3

#endif /* NOISESENSOR_H */


