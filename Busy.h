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
    virtual void proceed(TableComposite *tableComp);
    virtual void hold(TableComposite *tableComp);
    Busy();
};

#endif