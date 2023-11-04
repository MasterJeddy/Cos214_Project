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
    virtual void notifyWaiter() = 0;
    virtual void attach(Waiter *waiter) = 0;
    virtual void detach(Waiter *waiter) = 0;
};

#endif