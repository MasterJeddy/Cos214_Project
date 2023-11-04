//===-- COS214_Project/Update.cpp - Update class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the Update class. Update serves
/// as the concrete command in the command design. It is the most important
/// command in the entire system as it tells the entire system to move one
/// step forward. It is the class that triggers all the other classes.
///
//===----------------------------------------------------------------------===//

#include "Update.h"
#include "Clock.h"
void Update::execute() {
  Clock::instance().tick();
  floorController->update();
  kitchenController->update();
}

UserCommand *Update::clone() {
  return new Update(floorController,kitchenController);
}

COMMANDS Update::getType() {
  return COMMANDS::UPDATE;
}

Update::Update(FloorController *floorController, KitchenController *kitchenController) {
  this->floorController = floorController;
  this->kitchenController = kitchenController;
}

Update::~Update() = default;
