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

class MaitreD : public Observer
{
private:
    Floor *floor;

public:
    MaitreD(int id);
    virtual void notify(TableComponent* component);
};

#endif