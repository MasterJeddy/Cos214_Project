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
#include "Clock.h"

void FloorController::hireWaiter()
{
    Floor::instance()->addWaiter();
    //Floor::instance()->assignTablesToWaiters();
}

void FloorController::update()
{
    if (Clock::instance().getTime("AddCustomer")>3){
      Floor::instance()->addWaitingCustomer();
      Floor::instance()->addWaitingCustomer();
      Clock::instance().removeTime("AddCustomer");
    }
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
void FloorController::reset() {
    Floor::instance()->reset();
}
