//===-- COS214_Project/Update.h - Update class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the Update class. Update serves
/// as the concrete command in the command design. It is the most important
/// command in the entire system as it tells the entire system to move one
/// step forward. It is the class that triggers all the other classes.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__UPDATE_H
#define COS214_PROJECT__UPDATE_H

#include "UserCommand.h"
class Update : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~Update() override;
};

#endif //COS214_PROJECT__UPDATE_H
