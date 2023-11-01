//===-- COS214_Project/IOInterface.h - IOInterface class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the IOInterface class. IOInterface will
/// serve as an invoker in the command and the main class through which user
/// can interact with the system. The entire system will be driven forward
/// by the commands emitted by this class. It will also serve the roll of renderer
/// for the entire system.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_INPUTPOLL_H
#define COS214_PROJECT_INPUTPOLL_H

#include "CommandLog.h"
#include "Commands.h"
#include "Update.h"
class Logs;

enum DRAW_FLAGS {
    DRAW_LOG  = 1 << 0,
    DONT_DRAW_HELP= 1 << 1,
    DRAW_SAVES = 1 << 2
};

class IOInterface {
private:
  CommandLog* commandLog;
  Logs* logs;
  int drawState = DONT_DRAW_HELP;

  void render();
  UserCommand* queryUser();
public:
  void addFlag(DRAW_FLAGS flag);
  void removeFlag(DRAW_FLAGS flag);
  bool checkFlag(DRAW_FLAGS flag) const;

  void poll();


  void resetToLog(CommandLog* log);

  IOInterface();

  ~IOInterface();
};

#include "Logs.h"

#endif //COS214_PROJECT_INPUTPOLL_H
