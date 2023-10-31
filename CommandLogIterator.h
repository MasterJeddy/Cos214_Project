//
// Created by maili on 2023/10/31.
//

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
