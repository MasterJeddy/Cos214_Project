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
  /// \brief
  void first();
  /// \brief
  void next();
  /// \brief
  /// \return
  bool isDone();
  /// \brief
  /// \return
  UserCommand* currentItem();
  /// \brief
  /// \param commandLog
  explicit CommandLogIterator(CommandLog* commandLog);
};
#include "CommandLog.h"


#endif //COS214_PROJECT__COMMANDLOGITERATOR_H
