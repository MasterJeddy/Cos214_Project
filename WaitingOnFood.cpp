//===-- COS214_Project/WaitingOnFood.cpp - WaitingOnFood class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the WaitingOnFood.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "WaitingOnFood.h"

WaitingOnFood::WaitingOnFood(){
    this->name = "WaitingOnFood";
}

void WaitingOnFood::proceed(TableComposite* tableComp){
    TableState* tempy = new Eating();
    tableComp->setTableState(tempy);
}

void WaitingOnFood::hold(TableComposite* tableComp){
    
}



