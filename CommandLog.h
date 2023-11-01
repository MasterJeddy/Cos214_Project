//===-- COS214_Project/CommandLog.h - CommandLog class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the CommandLog class. CommandLog will
/// serve as an originator in the memento pattern. As the EventPoll emits commands
/// this class will log them. This log can be used by the EventPoll to be rolled
/// back to. In practise this will mean all commands in the log will have to be
/// rerun by the system at a much faster rate the usual play.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__COMMANDLOG_H
#define COS214_PROJECT__COMMANDLOG_H

#include <vector>
#include <string>
#include "UserCommand.h"
#include "CommandLogIterator.h"

class IOInterface;
class SavedLog;

class CommandLog {
private:
  IOInterface* inputPoll;
  std::vector<UserCommand*>* commands;
public:
  /// \brief
  /// \param log
  void load(SavedLog* log);
  /// \brief
  /// \return
  SavedLog* save();
  /// \brief
  /// \param com
  void addEntry(UserCommand* com);
  /// \brief
  /// \param inputPoll
  explicit CommandLog(IOInterface* inputPoll);
  /// \brief
  ~CommandLog();
  /// \brief
  /// \return
  CommandLogIterator* createIterator();
  friend class CommandLogIterator;
};

#include "IOInterface.h"
#include "SavedLog.h"

#endif //COS214_PROJECT__COMMANDLOG_H
