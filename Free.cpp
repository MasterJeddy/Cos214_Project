//===-- COS214_Project/Free.cpp - Free class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Free.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "Free.h"



void Free::proceed(TableComposite* tableComp){
    TableState* tempy = new Occupied();
    tableComp->setTableState(tempy);
}

void Free::hold(TableComposite* tableComp){
    
}

Free::Free(){
    this->name = "Free";
}



