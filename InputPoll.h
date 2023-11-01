//===-- COS214_Project/InputPoll.h - InputPoll class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the InputPoll class. InputPoll will
/// serve as an invoker in the command and the main class through which user
/// can interact with the system. The entire system will be driven forward
/// by the commands emitted by this class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_INPUTPOLL_H
#define COS214_PROJECT_INPUTPOLL_H

#include "CommandLog.h"
#include "Commands.h"
#include "Update.h"
class Logs;


class InputPoll {
private:
  CommandLog* commandLog;
  Logs* logs;
public:
  UserCommand* queryUser();

  void poll();

  void resetToLog(CommandLog* log);

  InputPoll();

  ~InputPoll();

};

#include "Logs.h"

#endif //COS214_PROJECT_INPUTPOLL_H