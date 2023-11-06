//===-- COS214_Project/BillComponent.h - BillComponent class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BillComponent class which acts here as the
/// the Component participant in the Composite design pattern. This was done so that
/// a bill object could be split up into sub-bills if the table wanted to do so.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BILLCOMPONENT_H
#define COS214_PROJECT_BILLCOMPONENT_H
#include <string>
class BillComponent
{

public:
    /// \brief Destructor for the billcomponent class.
    virtual ~BillComponent();
    /// \brief Adds a component to the children vector.
    /// \param component This is the subbill/billComposite that will be added.
    virtual void add(BillComponent *component) = 0;
    /// \brief Removes a component from the children vector.
    /// \param component This is the subbill/billComposite that will be removed.
    virtual void remove(BillComponent *component) = 0;
    /// \brief Gets the total of the bill.
    /// \return Returns a double of the total of the bill.
    virtual double getTotal() = 0;
    /// \brief Returns the name of the bill.
    /// \return Returns the name of the bill as a string.
    virtual std::string getName() = 0;
};

#endif