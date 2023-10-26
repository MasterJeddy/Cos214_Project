//===-- COS214_Project/Table.h - Table class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Table class which acts here as the Composite participant in
/// the Composite design pattern. This class implements the interface provided by the TableComponent class.
/// It contains children that are either composites(Table objects) or leaves(Customer objects), meaning customers
/// can be added to a table and also a table can be added to another table to increase its size as required.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLE_H
#define COS214_PROJECT_TABLE_H

#include "TableComponent.h"

class Table : public TableComponent
{
};

#endif