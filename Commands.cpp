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
  floorController->hireMaitreD();
}

UserCommand *HireMaitreD::clone() {
  return new HireMaitreD(floorController);
}

COMMANDS HireMaitreD::getType() {
  return COMMANDS::HIRE_MAITRE_D;
}

HireMaitreD::HireMaitreD(FloorController *floorController) {
  this->floorController = floorController;
}

HireMaitreD::~HireMaitreD() = default;

void BuyTable::execute() {
  floorController->buyTable();
}

UserCommand *BuyTable::clone() {
  return new BuyTable(floorController);
}

COMMANDS BuyTable::getType() {
  return COMMANDS::BUY_TABLE;
}
BuyTable::BuyTable(FloorController *floorController) {
  this->floorController = floorController;
}

BuyTable::~BuyTable()  =default;

void ExpandFloor::execute() {
  floorController->expandFloor();
}

UserCommand *ExpandFloor::clone() {
  return new ExpandFloor(floorController);
}

COMMANDS ExpandFloor::getType() {
  return COMMANDS::EXPAND_FLOOR;
}
ExpandFloor::ExpandFloor(FloorController *floorController) {
  this->floorController = floorController;
}

ExpandFloor::~ExpandFloor() = default;

void HireWaiter::execute() {
  floorController->hireWaiter();
}

UserCommand *HireWaiter::clone() {
  return new HireWaiter(floorController);
}

COMMANDS HireWaiter::getType() {
  return COMMANDS::HIRE_WAITER;
}
HireWaiter::HireWaiter(FloorController *floorController) {
  this->floorController = floorController;
}

HireWaiter::~HireWaiter() =default;

void ExpandKitchen::execute() {

}

UserCommand *ExpandKitchen::clone() {
  return new ExpandKitchen(kitchenController);
}

COMMANDS ExpandKitchen::getType() {
  return COMMANDS::EXPAND_KITCHEN;
}
ExpandKitchen::ExpandKitchen(KitchenController *kitchenController) {
  this->kitchenController = kitchenController;
}

ExpandKitchen::~ExpandKitchen() =default;

void HireChef::execute() {

}

UserCommand *HireChef::clone() {
  return new HireChef(kitchenController);
}

COMMANDS HireChef::getType() {
  return COMMANDS::HIRE_CHEF;
}
HireChef::HireChef(KitchenController *kitchenController) {
  this->kitchenController = kitchenController;
}

HireChef::~HireChef() = default;

void BuyStock::execute() {

}

UserCommand *BuyStock::clone() {
  return new BuyStock(kitchenController);
}

COMMANDS BuyStock::getType() {
  return COMMANDS::BUY_STOCK;
}

BuyStock::BuyStock(KitchenController *kitchenController) {
  this->kitchenController = kitchenController;
}

BuyStock::~BuyStock() = default;


void ToggleHelp::execute() {
  if (ioInterface->checkFlag(DONT_DRAW_HELP)){
    ioInterface->removeFlag(DONT_DRAW_HELP);
  } else {
    ioInterface->addFlag(DONT_DRAW_HELP);
  }
}

UserCommand *ToggleHelp::clone() {
  return new ToggleHelp(ioInterface);
}

COMMANDS ToggleHelp::getType() {
  return COMMANDS::TOGGLE_HELP;
}

ToggleHelp::ToggleHelp(IOInterface *IoInterface) {
  this->ioInterface = IoInterface;
}
void ToggleHelp::setIOInterface(IOInterface *ip) {
  ioInterface = ip;
}

ToggleHelp::~ToggleHelp() = default;

void ToggleLog::execute() {
  if (ioInterface->checkFlag(DRAW_LOG)){
    ioInterface->removeFlag(DRAW_LOG);
  } else {
    ioInterface->addFlag(DRAW_LOG);
  }
}

UserCommand *ToggleLog::clone() {
  return new ToggleLog(ioInterface);
}

COMMANDS ToggleLog::getType() {
  return COMMANDS::TOGGLE_LOG;
}

ToggleLog::ToggleLog(IOInterface *IoInterface) {
  this->ioInterface = IoInterface;
}
void ToggleLog::setIOInterface(IOInterface *ip) {
  ioInterface = ip;
}

ToggleLog::~ToggleLog()=default;
