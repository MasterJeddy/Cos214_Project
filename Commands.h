//===-- COS214_Project/Commands.h - Commands class definitions ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of several concrete commands in the
/// command pattern. Specifically HireMaitreD, BuyTable, ExpandFloor,
/// HireWaiter, ExpandKitchen, HireChef and BuyStock. What these commands
/// all have in common is that they will simple call corresponding functions
/// on the KitchenController and FloorController facades. e.g. BuyStock will
/// call the buyStock method on KitchenController.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__COMMANDS_H
#define COS214_PROJECT__COMMANDS_H

#include "UserCommand.h"

class HireMaitreD : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~HireMaitreD() override;

};

class BuyTable : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~BuyTable() override;
};

class ExpandFloor : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~ExpandFloor() override;

};

class HireWaiter : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~HireWaiter() override;
};

class ExpandKitchen : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~ExpandKitchen() override;
};

class HireChef : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~HireChef() override;
};

class BuyStock : public UserCommand{
public:
  void execute() override;
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~BuyStock() override;
};


#endif //COS214_PROJECT__COMMANDS_H
