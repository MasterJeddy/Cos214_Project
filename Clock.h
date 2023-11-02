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
  /// \brief Instance function of the clock singleton
  ///
  /// A static function which returns the a reference to the singular clock object. Also creates the clock
  /// if necessary.
  ///
  /// \return A reference to the singular clock instance
  static Clock& instance();
  /// \brief Get the time associated with identification string.
  ///
  /// This returns the amount of tics that have passed on a timer linked to an identification string
  /// since the first time this function was called (this function creates and associates a timer
  /// with the id string if such a timer thus not already exit).
  ///
  /// \param me This is the identification string of the timer
  /// \return The amount of ticks since timer created
  int getTime(const std::string& me);
  /// \brief Check weather an identification string has timer
  ///
  /// This function checks weather the passed in identification string has a timer associated with it
  /// or not. Returns true if it does.
  ///
  /// \param me This is the identification string of the timer
  /// \return True if there is a timer associated with the identification string.
  bool hasTime(const std::string& me);
  /// \brief Removes timer associated with identification string.
  ///
  ///  This function removes the timer associated with the identification string from the singleton.
  ///
  /// \param me This is the identification string of the timer
  void removeTime(const std::string& me);
  /// \brief Lets the clock tick
  ///
  /// Make the clock tick by incrementing the value of each timer in the singleton but one.
  void tick();
protected:
  /// Constructor blocked from being accessed by rest of system.
  Clock();
  /// Copy constructor blocked from being accessed by rest of system.
  /// \param clock
  Clock(const Clock& clock);
  /// Assigment operator blocked from being accessed by rest of system.
  /// \return
  Clock& operator=(const Clock&);
  /// Destructor operator blocked from being accessed by rest of system.
  ~Clock();
};

#endif //COS214_PROJECT__CLOCK_H
