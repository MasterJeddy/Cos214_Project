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
    MaitreD(int id);
    virtual ~MaitreD();
    virtual void notify(Customer *customer);
    virtual void notify(TableComposite *table);
};

#endif