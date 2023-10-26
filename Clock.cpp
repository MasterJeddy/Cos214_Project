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
#include "Clock.h"
Clock &Clock::instance() {
  static Clock onlyInstance_;
  return onlyInstance_;
}
Clock::Clock() {
  timers = std::map<std::string,int>();
}

int Clock::getTime(std::string me) {
  return 0;
}
bool Clock::hasTime(std::string me) {
  return false;
}

Clock::Clock(const Clock &clock)=default;
Clock &Clock::operator=(const Clock &) = default;
Clock::~Clock() =default;
