//===-- COS214_Project/WaitingOnWaiter.cpp - WaitingOnWaiter class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the WaitingOnWaiter.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "WaitingOnWaiter.h"

WaitingOnWaiter::WaitingOnWaiter(){
    this->name = "WaitingOnWaiter";
}

void WaitingOnWaiter::proceed(TableComposite* tableComp){
    TableState* tempy = new WaitingOnFood();
    tableComp->setTableState(tempy);
}

void WaitingOnWaiter::hold(TableComposite* tableComp){
    //Table rejected the service of the waiter and therefore the state needs to transition to the "Busy state". The context will call the hold() function if the service was rejected.
    TableState* tempy = new Busy();
    tableComp->setTableState(tempy);
}




