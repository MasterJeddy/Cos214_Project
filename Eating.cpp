//===-- COS214_Project/Eating.cpp - Eating class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Eating.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "Eating.h"

Eating::Eating(){
    
}

void Eating::proceed(TableComposite* tableComp){
    TableState* tempy = new Bill();
    tableComp->setTableState(tempy);
}

void Eating::hold(TableComposite* tableComp){
    
}



