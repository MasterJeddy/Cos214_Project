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
    /// \brief This is the constructor for subBill.
    /// \param itemName This is the name of the item.
    /// \param itemCost This is cost of the item.
    SubBill(std::string itemName, double itemCost);
    /// \brief This is the desturctor for the SubBill class.
    virtual ~SubBill();
    /// \brief  This will return the total for the bill.
    /// \return This will return a double for the bill.
    virtual double getTotal();
    /// \brief This will return a name for the bill.
    /// \return This will return the name for the bill as a string.
    virtual std::string getName();
    
    
    virtual void add(BillComponent *component);
    virtual void remove(BillComponent *component);
};

#endif