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

class TableState
{
   
    public:
    virtual void proceed() = 0;
    virtual void hold() = 0;
    TableState();
};

#endif