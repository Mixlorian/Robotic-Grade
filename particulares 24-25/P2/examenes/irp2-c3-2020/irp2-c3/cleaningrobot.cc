#include "cleaningrobot.h" 

using namespace C3;
    CleaningRobot::CleaningRobot(const std::string name):Robot(name){}
     CleaningRobot::~CleaningRobot()=default;
    
    bool CleaningRobot::canWalk (){
        return true;
    }
    bool CleaningRobot::canTalk (){
        return true;
    }

    void CleaningRobot::set_room(const std::string& r){
        theRoom = r;
    }
    std::string CleaningRobot::get_room(){
        return theRoom;
    }