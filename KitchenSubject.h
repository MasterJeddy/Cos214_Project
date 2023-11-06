//===-- COS214_Project/KitchenSubject.h - KitchenSubject class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the KitchenSubject class which acts as a Subject in the Observer
/// design pattern.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_KITCHENSUBJECT_H
#define COS214_PROJECT_KITCHENSUBJECT_H

#include <vector>
#include "Waiter.h"

class KitchenSubject
{
protected:
    std::vector<Waiter *> waiterList;

public:
    virtual ~KitchenSubject();
    /// \brief Notifies all waiters in the observer list that orders are finished
    virtual void notifyWaiter() = 0;
    /// \brief adds a waiter to the observer list
    /// \param waiter Waiter object to be added
    virtual void attach(Waiter *waiter) = 0;
    /// \brief removes a waiter from the observer list
    /// \param waiter Waiter object to be removed
    virtual void detach(Waiter *waiter) = 0;
};

#endif