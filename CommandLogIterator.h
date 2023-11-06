//===-- COS214_Project/CommandLogIterator.h - CommandLogIterator class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the CommandLogIterator class.
/// CommandLogIterator will serve as an concreteIterator in the iterator
/// design pattern. It will be used buy InputPoll to traverse the CommandLog
/// when resetting itself.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__COMMANDLOGITERATOR_H
#define COS214_PROJECT__COMMANDLOGITERATOR_H

#include <vector>
#include "UserCommand.h"
class CommandLog;

class CommandLogIterator {
private:
  CommandLog* commandLog;
  std::vector<UserCommand*>::iterator it;
public:
  /// \brief Sets the iterator to the beginning of the log
  void first();
  /// \brief Moves iterator to the next item in the log
  void next();
  /// \brief Checks if iterator has hit the end of the log
  /// \return true if iterator is at end of the log. False otherwise
  bool isDone();
  /// \brief Returns the command the iterator is currently on
  /// \return Command iterator is currently on
  UserCommand* currentItem();
  /// \brief The constructor for the CommandLogIterator
  /// \param commandLog The CommandLog for which the iterator was constructed.
  explicit CommandLogIterator(CommandLog* commandLog);
};
#include "CommandLog.h"


#endif //COS214_PROJECT__COMMANDLOGITERATOR_H
