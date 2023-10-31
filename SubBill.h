//===-- COS214_Project/SubBill.h - SubBill class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SubBill class which acts here as the
/// the leaf participant in the Composite design pattern. This file implements the
/// BillComponent class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_SUBBILL_H
#define COS214_PROJECT_SUBBILL_H
#include "BillComponent.h"

class SubBill : public BillComponent
{
private:
    std::string name;
    double total;

public:
    SubBill(std::string itemName, double itemCost);
    virtual double getTotal();
    virtual std::string getName();
    virtual void add(BillComponent *component);
    virtual void remove(BillComponent *component);
    // virtual ~SubBill();
};

#endif