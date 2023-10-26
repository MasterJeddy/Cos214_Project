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
      //did not find timer
      timers[me] = 0;
      return timers[me];
    }
}
bool Clock::hasTime(const std::string& me) {
  return false;
}
void Clock::tick() {

}
void Clock::removeTime(const std::string &me) {

}

Clock::Clock(const Clock &clock)=default;
Clock &Clock::operator=(const Clock &) = default;
Clock::~Clock() =default;
