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
#include "FloorController.h"

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
  FloorController* floorController;

  /// \brief Renders other objects in text format
  void render();
  /// \brief Ask UserInput and returns command to be executed
  /// \return Command to be executed
  UserCommand* queryUser();
public:
  /// \brief Sets flag
  /// \param flag Flag to be set
  void addFlag(DRAW_FLAGS flag);
  /// \brief Unsets flag
  /// \param flag Flag to be unset
  void removeFlag(DRAW_FLAGS flag);
  /// \brief Checks if flag is set
  /// \param flag Flag to check
  /// \return True if flag to check is set false otherwise
  bool checkFlag(DRAW_FLAGS flag) const;
  /// \brief  Works as an onUpdate. Checks input from user execute commands and renders the
  /// renders system state.
  void poll();
  /// \brief Resets system and execute all commands in log. Excluding Save and Load Commands.
  /// thus not render anything.
  /// \param log Log's commands to be rerun.
  void resetToLog(CommandLog* log);
  /// \brief Constructor for IOInterface
  IOInterface();
  /// \brief Destructor for IOInterface
  ~IOInterface();
};

#include "Logs.h"

#endif //COS214_PROJECT_INPUTPOLL_H
