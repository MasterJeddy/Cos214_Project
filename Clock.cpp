//===-- COS214_Project/Clock.h - Clock class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of an Clock class. The Clock is a
/// singleton that will be used through out the system the synchronise a
/// actions between classes.
///
//===----------------------------------------------------------------------===//

#include <string>
#include <stdexcept>
#include "Clock.h"
Clock &Clock::instance() {
  static Clock onlyInstance_;
  return onlyInstance_;
}
Clock::Clock() {
  timers = std::map<std::string,int>();
}

int Clock::getTime(const std::string& me) {
    try {
       timers.at(me);
       //found timer in map
       return timers[me];
    } catch (std::out_of_range& e)  {
      //did not find timer in map
      timers[me] = 0;
      return timers[me];
    }
}

bool Clock::hasTime(const std::string& me) {
  try {
    timers.at(me);
    //found timer in map
    return true;
  } catch (std::out_of_range& e)  {
    //did not find timer in map
    return false;
  }
}

void Clock::tick() {
  //Add one to all timers
  for (auto& time: timers) {
    time.second += 1;
  }
}

void Clock::removeTime(const std::string &me) {
    if (hasTime(me)){
      std::map<std::string ,int>::iterator it;
      it = timers.find (me);
      timers.erase (it);
    }
}
void Clock::reset() {
  timers.clear();
}

Clock::Clock(const Clock &clock)=default;
Clock &Clock::operator=(const Clock &) = default;
Clock::~Clock() =default;
