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

};

class BuyTable : public UserCommand{

};

class ExpandFloor : public UserCommand{

};

class HireWaiter : public UserCommand{

};

class ExpandKitchen : public UserCommand{

};

class HireChef : public UserCommand{

};

class BuyStock : public UserCommand{

};


#endif //COS214_PROJECT__COMMANDS_H
