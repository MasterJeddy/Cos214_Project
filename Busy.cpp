//===-- COS214_Project/Busy.cpp - Busy class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Busy.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "Busy.h"

Busy::Busy(){
    this->name = "Busy";
}

TableState *Busy::clone()
{
    return new Busy();
}

void Busy::proceed(TableComposite *tableComp)
{
    TableState* tempy = new WaitingOnWaiter();
    tableComp->setTableState(tempy);
}

void Busy::hold(TableComposite* tableComp){
    
}



