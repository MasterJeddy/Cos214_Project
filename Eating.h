//===-- COS214_Project/Eating.h - Eating class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Eating class which acts here as the
/// ConcreteState class of the state design pattern. 
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_EATING_H
#define COS214_PROJECT_EATING_H
#include "TableState.h"

class Eating: public TableState
{
   
    public:
    virtual void proceed(TableComposite* tableComp);
    virtual void hold(TableComposite* tableComp);
    Eating();
};

#endif