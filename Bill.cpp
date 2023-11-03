//===-- COS214_Project/Bill.cpp - Bill class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Bill.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "Bill.h"

Bill::Bill(){
    this->name = "Bill";
}

void Bill::proceed(TableComposite* tableComp){
    TableState* tempy = new Occupied();
    tableComp->setTableState(tempy);
}

void Bill::hold(TableComposite* tableComp){
    TableState* tempy = new Occupied();
    tableComp->setTableState(tempy);
}
