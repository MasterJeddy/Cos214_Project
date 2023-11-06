//===-- COS214_Project/BillComposite.h - BillComposite class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BillComposite class which acts here as the
/// the Composite participant in the Composite design pattern. This file implements the
/// BillComponent class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BILLCOMPOSITE_H
#define COS214_PROJECT_BILLCOMPOSITE_H
#include "BillComponent.h"
#include <vector>

class BillComposite : public BillComponent
{
private:
    std::vector<BillComponent *> children;
    std::string name;

public:
    /// @brief BillComposite constructor, that takes in a name. 
    /// @param compositeName This will set the name of the bill to the passed in parameter.
    BillComposite(std::string compositeName);
    /// @brief This is the destructor the BillComposite class.
    virtual ~BillComposite();
    /// @brief Removes a component from the children vector.
    /// @param component This is the subbill/billComposite that will be removed.
    virtual void add(BillComponent *component);
    /// @brief Gets the total of the bill.
    /// @return Returns a double of the total of the bill.
    virtual void remove(BillComponent *component);
     /// @brief Returns the name of the bill.
    /// @return Returns the name of the bill as a string.
    virtual double getTotal();
     /// @brief Returns the name of the bill.
    /// @return Returns the name of the bill as a string.
    virtual std::string getName();
};

#endif