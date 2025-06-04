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

#ifndef BATTLEROBOT_H
#define BATTLEROBOT_H

#include <boost/signals2.hpp>

#include "macros.h"
#include "robot.h"

namespace C3 {

  class BattleRobot : public Robot
  {
  public:
    BattleRobot(const std::string name, uint mapSize);
    virtual ~BattleRobot();
    
    virtual bool canWalk ();
    virtual bool canTalk ();
    virtual uint get_num_sensors();

    float get_attack_level ();
    void set_attack_level (float l);
    float get_damage ();
    void set_damage (float d);

    bool add_robot_at(uint x, uint y, RobotPtr r);

    /////////////
    // Signals //
    /////////////
    boost::signals2::signal<void (BattleRobot*, Robot*, uint x, uint y)> robotNotAddedSignal;
    
  private:
    float attackLevel;
    float damage;

    uint theMapSize;
    RobotPtr** map; // vector< vector<RobotPtr> > map;
  };

  DECLARE_PTR(BattleRobot);  // BattleRobotPtr
}  // C3

#endif /* BATTLEROBOT_H */
