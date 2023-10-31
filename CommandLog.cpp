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
void CommandLog::load(SavedLog* log) {
    while (!commands->empty()){
      delete commands->back();
      commands->pop_back();
    }

    for (auto com:*log->getCommands()){
      this->commands->push_back(com->clone());
    }
    inputPoll->resetToLog(this);
}

SavedLog* CommandLog::save() {
  return new SavedLog(commands);//This is wrong
}

void CommandLog::addEntry(UserCommand* com) {
  commands->push_back(com->clone());
}

CommandLog::CommandLog(InputPoll* inputPoll) {
  this->inputPoll = inputPoll;
  this->commands = new std::vector<UserCommand*>();
}

CommandLog::~CommandLog() {
  while (!commands->empty()){
    delete commands->back();
    commands->pop_back();
  }
  delete this->commands;
}
CommandLogIterator *CommandLog::createIterator() {
  return new CommandLogIterator(this);
}
