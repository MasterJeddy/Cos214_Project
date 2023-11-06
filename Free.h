//===-- COS214_Project/Free.h - Free class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Free class which acts here as the
/// ConcreteState class of the state design pattern.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_FREE_H
#define COS214_PROJECT_FREE_H
#include "TableComposite.h"
#include "TableState.h"
#include "Occupied.h"

class Free : public TableState
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
     /// @brief This is the constructor the Free state class. 
    Free();
    
    virtual std::string getName();
};

#endif