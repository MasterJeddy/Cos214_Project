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
// #include "TableComposite.h"
#include <string>

class TableComposite;
class TableState
{
protected:
    std::string name;

public:
    /// \brief This will clone a table state, acts as a prototype.
    
    virtual TableState *clone() = 0;
    /// \brief This will proceed to the next state.
    /// \param tableComp This is the table composite that needs to transition state.
    virtual void proceed(TableComposite *tableComp) = 0;
    
    /// \brief This will hold to the relevant state.
    /// \param tableComp This is the table composite that needs to transition.
    virtual void hold(TableComposite *tableComp) = 0;
    /// \brief This is the constructor for table state.
    TableState();
    /// \brief  This is a destructor of the table state.
    virtual ~TableState() = 0;
    /// \brief Gets the name of the table.
    /// \return  This will return the name of the table.
    virtual std::string getName();
};

#endif