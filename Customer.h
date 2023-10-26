//===-- COS214_Project/Customer.h - Customer class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Customer class which acts here as the Leaf participant in
/// the Composite design pattern. This class implements the interface provided by the TableComponent class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_CUSTOMER_H
#define COS214_PROJECT_CUSTOMER_H

#include "TableComponent.h"

class Customer : public TableComponent
{
};

#endif