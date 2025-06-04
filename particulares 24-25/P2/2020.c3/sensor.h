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

#ifndef SENSOR_H
#define SENSOR_H
#include <string>
namespace C3 {
  template <typename T>
  class Sensor{
  public:
    Sensor(const std::string name);
    virtual ~Sensor();
    std::string get_name();
    void set_level(T l);
    T get_level();
  private:
    std::string theName;
    T theLevel;
    // T *theDirLevel;
  };
}  // C3
#include "sensor.tcc"
#endif /* SENSOR_H */


