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

#ifndef BASICROBOT_H
#define BASICROBOT_H

#include <string>

#include "macros.h"
#include "robot.h"

namespace C3 {

  class BasicRobot : public Robot
  {
  public:
    BasicRobot(const std::string name);
    virtual ~BasicRobot();
    
    virtual bool canWalk ();
    virtual bool canTalk ();
  };

  DECLARE_PTR(BasicRobot);  // BasicRobotPtr
}  // C3

#endif /* BASICROBOT_H */
