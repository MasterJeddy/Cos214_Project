//===-- COS214_Project/MaitreD.h - MaitreD class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the MaitreD class which acts as a ConcreteObserver in the Observer
/// design pattern. A maitreD will be notified when a customer requests for a seat.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_MAITRED_H
#define COS214_PROJECT_MAITRED_H

#include "Observer.h"
#include "Floor.h"

#include <iostream>

class MaitreD : public Observer
{
private:
public:
    /// \brief sets the id of the maitreD, sets initial state to FREE and sets type of observer that it is
    /// \param id integer that is used to create the id of the waiter
    MaitreD(int id);

    /// \brief clears the list of tables assigned to this waiter
    virtual ~MaitreD();

    /// \brief called when a customer requests a seat
    /// \param customer the customer requesting a seat
    virtual void notify(Customer *customer);

    /// \brief called when a table requests the waiter's assistance
    /// \param table the table that is currently requesting assistance
    virtual void notify(TableComposite *table);

    friend class IOInterfaceGUI;
};

#endif