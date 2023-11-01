//===-- COS214_Project/SavedLog.h - SavedLog class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the SavedLog class. SavedLog serves
/// as the memento in the memento design. It stores the same same vector of
/// commands as the CommandLog class. It can be save and loaded with the uses
/// of the Logs Class.
///
//===----------------------------------------------------------------------===//


#ifndef COS214_PROJECT__SAVEDLOG_H
#define COS214_PROJECT__SAVEDLOG_H

#include "CommandLog.h"

class SavedLog {
private:
  std::vector<UserCommand*>* commands;
public:
  /// \brief Getter for commands vector
  /// \return Commands vector
  std::vector<UserCommand*>* getCommands();
  /// \brief Setter for commands vector
  /// \param commands New value for commands vector
  void setCommands(std::vector<UserCommand*>* commands);
  /// \brief Constructor for SavedLog
  /// \param commands Commands vector to store
  explicit SavedLog(std::vector<UserCommand*>* commands);
  /// \brief Destructor for SavedLog
  ~SavedLog();
};

#endif //COS214_PROJECT__SAVEDLOG_H
