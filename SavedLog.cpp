//===-- COS214_Project/SavedLog.cpp - SavedLog class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the SavedLog class. SavedLog serves
/// as the memento in the memento design. It stores the same same vector of
/// commands as the CommandLog class. It can be save and loaded with the uses
/// of the Logs Class.
///
//===----------------------------------------------------------------------===//

#include "SavedLog.h"
std::vector<UserCommand*>* SavedLog::getCommands() {
  return commands;
}
void SavedLog::setCommands(std::vector<UserCommand*>* commands) {
  delete this->commands;
  this->commands = commands;
}
SavedLog::SavedLog(std::vector<UserCommand*> *commands) {
  this->commands = commands;
}
SavedLog::~SavedLog() {
  delete this->commands;
}
