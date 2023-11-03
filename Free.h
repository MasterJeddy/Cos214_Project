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
    virtual void proceed(TableComposite *tableComp);
    virtual void hold(TableComposite *tableComp);
    Free();
    virtual std::string getName();
};

#endif