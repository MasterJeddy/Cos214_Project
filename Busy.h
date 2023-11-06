//===-- COS214_Project/Busy.h - Busy class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Busy class which acts here as the
/// ConcreteState class of the state design pattern.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BUSY_H
#define COS214_PROJECT_BUSY_H
#include "TableState.h"
#include "WaitingOnWaiter.h"
#include "TableComposite.h"

class Busy : public TableState
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
     /// @brief This is the constructor the Busy state class. 
    Busy();
};

#endif