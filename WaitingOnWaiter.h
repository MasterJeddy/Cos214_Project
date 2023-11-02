//===-- COS214_Project/WaitingOnWaiter.h - WaitingOnWaiter class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the WaitingOnWaiter class which acts here as the
/// ConcreteState class of the state design pattern. 
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_WAITINGONWAITER_H
#define COS214_PROJECT_WAITINGONWAITER_H
#include "TableState.h"
#include "WaitingOnFood.h"
#include "Busy.h"

class WaitingOnWaiter: public TableState
{
   
    public:
    virtual void proceed(TableComposite* tableComp);
    virtual void hold(TableComposite* tableComp);
    WaitingOnWaiter();
};

#endif