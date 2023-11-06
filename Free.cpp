//===-- COS214_Project/Free.cpp - Free class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Free.h file.
///
///
//===----------------------------------------------------------------------===//

#include "Free.h"

Free::Free()
{
    this->name = "Free";
}

std::string Free::getName()
{
    return this->name;
}

TableState *Free::clone()
{
    return new Free();
}

void Free::proceed(TableComposite *tableComp)
{
    TableState *tempy = new Occupied();
    tableComp->setTableState(tempy);
}

void Free::hold(TableComposite *tableComp)
{
}
