//===-- COS214_Project/FloorController.cpp - FloorController class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
///
///
//===----------------------------------------------------------------------===//

#include "FloorController.h"

void FloorController::hireWaiter()
{
    Floor::instance()->addWaiter();
}

void FloorController::update()
{
    Floor::instance()->requestSeat();
}

void FloorController::hireMaitreD()
{
    Floor::instance()->addMaitreD();
}

void FloorController::buyTable()
{
    Floor::instance()->addTable();
}

void FloorController::expandFloor()
{
}
