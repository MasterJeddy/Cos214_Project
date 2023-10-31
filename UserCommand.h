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

class UserCommand {
public:
  /// This function must be implemented by all use commands
  virtual void execute() =0;
};

#endif //COS214_PROJECT__USERCOMMAND_H