//===-- COS214_Project/Occupied.h - Occupied class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Occupied class which acts here as the
/// ConcreteState class of the state design pattern.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_OCCUPIED_H
#define COS214_PROJECT_OCCUPIED_H
#include "TableState.h"
#include "WaitingOnWaiter.h"

class Occupied : public TableState
{

public:
    virtual void proceed(TableComposite *tableComp);
    virtual void hold(TableComposite *tableComp);
    Occupied();
};

#endif