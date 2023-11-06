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

class WaitingOnWaiter : public TableState
{

public:
/// @brief This will return a clone of the state.
    /// @return This will return a clone of the current state as a TableState pointer.
    virtual TableState *clone();
     /// @brief This will proceed to the next state.
    /// @param tableComp This is the table composite that needs to transition state.
    virtual void proceed(TableComposite *tableComp);
     /// @brief This will hold to the relevant state.
    /// @param tableComp This is the table composite that needs to transition. 
    virtual void hold(TableComposite *tableComp);
     /// @brief This is the constructor the WaitingOnWaiter state class. 
    WaitingOnWaiter();
};

#endif