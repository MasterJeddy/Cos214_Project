//===-- COS214_Project/Occupied.cpp - Occupied class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Occupied.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "Occupied.h"

Occupied::Occupied(){
    this->name = "Occupied";
}

void Occupied::proceed(TableComposite* tableComp){
    TableState* tempy = new WaitingOnWaiter();
    tableComp->setTableState(tempy);
}

void Occupied::hold(TableComposite* tableComp){
    
}



