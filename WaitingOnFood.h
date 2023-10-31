//===-- COS214_Project/WaitingOnFood.h - WaitingOnFood class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the WaitingOnFood class which acts here as the
/// ConcreteState class of the state design pattern. 
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_WAITINGONFOOD_H
#define COS214_PROJECT_WAITINGONFOOD_H
#include "TableState.h"

class WaitingOnFood: public TableState
{
   
    public:
    virtual void proceed(TableComposite* tableComp);
    virtual void hold(TableComposite* tableComp);
    WaitingOnFood();
};

#endif