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

#include "UserCommand.h"
#include "CommandLog.h"

class CommandLogIterator {
private:
  CommandLog* commandLog;
  std::vector<UserCommand*>::iterator it;
public:
  void first();
  void next();
  bool isDone();
  UserCommand* currentItem();
  explicit CommandLogIterator(CommandLog* commandLog);
};

#endif //COS214_PROJECT__COMMANDLOGITERATOR_H
