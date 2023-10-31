//===-- COS214_Project/Commands.cpp - Commands class implementations ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of several concrete commands in the
/// command pattern. Specifically HireMaitreD, BuyTable, ExpandFloor,
/// HireWaiter, ExpandKitchen, HireChef and BuyStock. What these commands
/// all have in common is that they will simple call corresponding functions
/// on the KitchenController and FloorController facades. e.g. BuyStock will
/// call the buyStock method on KitchenController.
///
//===----------------------------------------------------------------------===//

#include "Commands.h"
void HireMaitreD::execute() {

}

UserCommand *HireMaitreD::clone() {
  return new HireMaitreD;
}

COMMANDS HireMaitreD::getType() {
  return COMMANDS::HIRE_MAITRE_D;
}

HireMaitreD::~HireMaitreD() = default;

void BuyTable::execute() {

}

UserCommand *BuyTable::clone() {
  return new BuyTable;
}

COMMANDS BuyTable::getType() {
  return COMMANDS::BUY_TABLE;
}

BuyTable::~BuyTable()  =default;

void ExpandFloor::execute() {

}

UserCommand *ExpandFloor::clone() {
  return new ExpandFloor;
}

COMMANDS ExpandFloor::getType() {
  return COMMANDS::EXPAND_FLOOR;
}

ExpandFloor::~ExpandFloor() = default;

void HireWaiter::execute() {

}

UserCommand *HireWaiter::clone() {
  return new HireWaiter;
}

COMMANDS HireWaiter::getType() {
  return COMMANDS::HIRE_WAITER;
}

HireWaiter::~HireWaiter() =default;

void ExpandKitchen::execute() {

}

UserCommand *ExpandKitchen::clone() {
  return nullptr;
}

COMMANDS ExpandKitchen::getType() {
  return COMMANDS::EXPAND_KITCHEN;
}

ExpandKitchen::~ExpandKitchen() =default;

void HireChef::execute() {

}

UserCommand *HireChef::clone() {
  return new HireChef;
}

COMMANDS HireChef::getType() {
  return COMMANDS::HIRE_CHEF;
}

HireChef::~HireChef() = default;

void BuyStock::execute() {

}

UserCommand *BuyStock::clone() {
  return new BuyStock;
}

COMMANDS BuyStock::getType() {
  return COMMANDS::BUY_STOCK;
}

BuyStock::~BuyStock() = default;
