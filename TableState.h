//===-- COS214_Project/TableState.h - TableState class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TableState class which acts here as the
/// state class of the state design pattern. 
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLESTATE_H
#define COS214_PROJECT_TABLESTATE_H
#include "TableComposite.h"
#include <string>

class TableState
{
    private: 
    std::string name;
    public:
    virtual void proceed(TableComposite* tableComp) = 0;
    virtual void hold(TableComposite* tableComp) = 0;
    TableState();
    std::string getName();
};

#endif