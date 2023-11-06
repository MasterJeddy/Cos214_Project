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
  /// \brief Loads SavedLog and rolls IOInterface to it.
  /// \param log The SavedLog to be loaded to.
  void load(SavedLog* log);
  /// \brief Create a SavedLog from the currentLog
  /// \return The SavedLog created Note: must deleted by caller
  SavedLog* save();
  /// \brief Appends a new command to the log
  /// \param com The command to be appended
  void addEntry(UserCommand* com);
  /// \brief The constructor of the CommandLog class
  /// \param inputPoll The InputPoll to which the CommandLog is bound
  explicit CommandLog(IOInterface* inputPoll);
  /// \brief The destructor of the CommandLog
  ~CommandLog();
  /// \brief Creates and iterator so other classes can traverse the commands in commandLog
  /// \return The iterator created Note: must be deleted by caller
  CommandLogIterator* createIterator();
  friend class CommandLogIterator;
};

#include "IOInterface.h"
#include "SavedLog.h"

#endif //COS214_PROJECT__COMMANDLOG_H
