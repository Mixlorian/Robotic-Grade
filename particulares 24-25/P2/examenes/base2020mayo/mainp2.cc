
#include <iostream>

#include "battlerobot.h"
#include "cleaningrobot.h"
#include "basicrobot.h"

const uint MAPSIZE_A = 10;
const uint MAPSIZE_B = 3;
const uint NSENSORS  = 8;

void robotNotAdded(C3::BattleRobotPtr br, C3::RobotPtr r, uint x, uint y) {
  std::cout << "Could not add Robot (" << r->get_name() << " to "
            << br->get_name() << " @(" << x << ", " << y << ").\n";

  delete r;
}

int main(int argc, char *argv[])
{

  std::cout << "0. Total robots: " << C3::Robot::get_total_robots_created() << std::endl;

  ///////
  // 1 //
  ///////
  C3::RobotPtr r2 = new C3::BattleRobot("R2D2", MAPSIZE_A);

  dynamic_cast<C3::BattleRobotPtr>(r2) -> robotNotAddedSignal.connect(robotNotAdded);
  
  std::cout << "1. Total robots: " << C3::Robot::get_total_robots_created() << std::endl;

  for (uint y = 0; y < MAPSIZE_A; y++) {
    for (uint x = 0; x <= MAPSIZE_A; x++) {
      C3::RobotPtr c = nullptr;
      if (x % 2) {
        c = new C3::CleaningRobot("CleaningRobot_" + std::to_string(10*y + x));
        dynamic_cast<C3::CleaningRobotPtr>(c)->set_room(std::to_string(10*y + x));
      } else  {
        c = new C3::CleaningRobot("BasicRobot_" + std::to_string(10*y + x));
      }
      for (uint s = 0; s < NSENSORS; s++) {
        auto ns = new C3::NoiseSensor("NS_" + std::to_string(s));
        c -> add_sensor(ns);
      }
      dynamic_cast<C3::BattleRobotPtr>(r2) -> add_robot_at(x,y,c);
    }
  }
  C3::BattleRobotPtr ar2 = dynamic_cast<C3::BattleRobotPtr>(r2);
  ar2->set_attack_level(0.5);
  ar2->set_damage(0.5);

  std::cout << "2. BattleRobot ar2 num. sensors: " << ar2 -> get_num_sensors()
            << '\n';

  ///////
  // 2 //
  ///////
  std::cout << "3. Total robots: " << C3::Robot::get_total_robots_created() << std::endl;

  C3::BattleRobotPtr br = new C3::BattleRobot("Robby", MAPSIZE_B);
  br -> add_sensor(new C3::NoiseSensor("BATTLE NOISE-SENSOR"));
  for (uint y = 0; y < MAPSIZE_B; y++) {
    for (uint x = 0; x < MAPSIZE_B; x++) {
      auto c = new C3::BasicRobot("BasicRobot" + std::to_string(10*y + x));
      br -> add_robot_at(x,y,c);
      for (uint s = 0; s < NSENSORS; s++) {
        auto ns = new C3::NoiseSensor("NS_" + std::to_string(s));
        c -> add_sensor(ns);
      }
    }
  }
  br->set_attack_level(0.75);
  br->set_damage(0.25);

  std::cout << "4. BattleRobot br num. sensors: " << br -> get_num_sensors()
            << '\n';

  std::cout << "5. Total robots: " << C3::Robot::get_total_robots_created() << std::endl;

  /////////////////
  // Free Memory //
  /////////////////
  delete r2;
  delete br;

  
  return 0;
}
