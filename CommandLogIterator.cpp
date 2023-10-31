//
// Created by maili on 2023/10/31.
//

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
