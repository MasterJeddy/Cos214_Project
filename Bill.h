//===-- COS214_Project/Bill.h - Bill class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Bill class which acts here as the
/// ConcreteState class of the state design pattern. 
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BILL_H
#define COS214_PROJECT_BILL_H
#include "TableState.h"

class Bill: public TableState
{
   
    public:
    virtual void proceed(TableComposite* tableComp);
    virtual void hold(TableComposite* tableComp);
    Bill();
};

#endif