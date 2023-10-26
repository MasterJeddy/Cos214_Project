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
  ///
  /// \return
  static Clock& instance();
  ///
  /// \param me
  /// \return
  int getTime(const std::string& me);
  ///
  /// \param me
  /// \return
  bool hasTime(const std::string& me);
  ///
  /// \param me
  void removeTime(const std::string& me);
  ///
  void tick();
protected:
  ///
  Clock();
  ///
  /// \param clock
  Clock(const Clock& clock);
  ///
  /// \return
  Clock& operator=(const Clock&);
  ///
  ~Clock();
};

#endif //COS214_PROJECT__CLOCK_H
