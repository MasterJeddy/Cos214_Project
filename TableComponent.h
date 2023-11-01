//===-- COS214_Project/TableComponent.h - TableComponent class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TableComponent class which acts here as the
/// the Component participant in the Composite design pattern. This class provides the interface with
/// which the clients interact. For example when taking an order, the waiter will interact with an object that
/// implements this interface.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLECOMPONENT_H
#define COS214_PROJECT_TABLECOMPONENT_H

#include "Observer.h"
#include <vector>

#include "Constants.cpp"

class TableComponent
{
protected:
    std::string id;
    std::vector<Observer *> observerList;

public:
    TableComponent();
    virtual ~TableComponent();

    virtual void attachObserver(Observer *observer);
    virtual void detachObserver(Observer *observer);
    virtual void request() = 0;
};

#endif