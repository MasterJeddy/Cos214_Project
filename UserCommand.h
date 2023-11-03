//===-- COS214_Project/UserCommand.h - UserCommand class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the UserCommand class. UserCommand
/// serves as the command in the command pattern. All the other commands
/// in the system from it.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__USERCOMMAND_H
#define COS214_PROJECT__USERCOMMAND_H

#include "FloorController.h"
class KitchenController;

enum class COMMANDS {
  SAVE,
  LOAD,
  TOGGLE_HELP,
  TOGGLE_LOG,
  HIRE_MAITRE_D,
  BUY_TABLE,
  EXPAND_FLOOR,
  HIRE_WAITER,
  UPDATE,
  EXPAND_KITCHEN,
  HIRE_CHEF,
  BUY_STOCK
};

class UserCommand {
public:
  /// \brief This function must be implemented by all use commands
  virtual void execute() =0;
  /// \brief Clone functions for children to implement
  /// \return Pointer to cloned child
  virtual UserCommand* clone() = 0;
  /// \brief Child must return ENUM corresponding to child type
  /// \return The correct COMMANDS ENUM member
  virtual COMMANDS getType() =0;
  /// \brief Destructor for UserCommand
  virtual ~UserCommand();

};

#endif //COS214_PROJECT__USERCOMMAND_H
