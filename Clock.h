//===-- COS214_Project/Clock.h - Clock class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of an Clock class. The Clock is a
/// singleton that will be used through out the system the synchronise a
/// actions between classes.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__CLOCK_H
#define COS214_PROJECT__CLOCK_H

#include <map>


class Clock {
private:
  std::map<std::string,int> timers;
public:
  static Clock& instance();
  int getTime(const std::string& me);
  bool hasTime(const std::string& me);
  void removeTime(const std::string& me);
  void tick();
protected:
  Clock();
  Clock(const Clock& clock);
  Clock& operator=(const Clock&);
  ~Clock();
};

#endif //COS214_PROJECT__CLOCK_H
