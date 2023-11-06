//===-- COS214_Project/CommandLogIterator.cpp - CommandLogIterator class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the CommandLogIterator class.
/// CommandLogIterator will serve as an concreteIterator in the iterator
/// design pattern. It will be used buy InputPoll to traverse the CommandLog
/// when resetting itself.
///
//===----------------------------------------------------------------------===//

#include "CommandLogIterator.h"
void CommandLogIterator::first() {
  it = commandLog->commands->begin();
}
void CommandLogIterator::next() {
  it++;
}
bool CommandLogIterator::isDone() {
  return  !(it < commandLog->commands->end());
}
UserCommand *CommandLogIterator::currentItem() {
  return *it;
}
CommandLogIterator::CommandLogIterator(CommandLog *commandLog) {
  this->commandLog = commandLog;
}
