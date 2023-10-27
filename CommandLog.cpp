//===-- COS214_Project/CommandLog.cpp - CommandLog class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the CommandLog class. CommandLog will
/// serve as an originator in the memento pattern. As the EventPoll emits commands
/// this class will log them. This log can be used by the EventPoll to be rolled
/// back to. In practise this will mean all commands in the log will have to be
/// rerun by the system at a much faster rate than usual play.
///
//===----------------------------------------------------------------------===//

#include "CommandLog.h"
void CommandLog::load(SavedLog log) {

}
SavedLog CommandLog::save() {
  return SavedLog();
}
void CommandLog::loadFromFile(std::string file) {

}
void CommandLog::saveToFile(std::string file) {

}
void CommandLog::addEntry(UserCommand com) {

}
CommandLog::CommandLog() {

}
