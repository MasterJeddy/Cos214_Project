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
  /// \brief
  void render();
  /// \brief
  /// \return
  UserCommand* queryUser();
public:
  /// \brief
  /// \param flag
  void addFlag(DRAW_FLAGS flag);
  /// \brief
  /// \param flag
  void removeFlag(DRAW_FLAGS flag);
  /// \brief
  /// \param flag
  /// \return
  bool checkFlag(DRAW_FLAGS flag) const;
  /// \brief
  void poll();
  /// \brief
  /// \param log
  void resetToLog(CommandLog* log);
  /// \brief
  IOInterface();
  /// \brief
  ~IOInterface();
};

#include "Logs.h"

#endif //COS214_PROJECT_INPUTPOLL_H
