//===-- COS214_Project/Waiter.h - Waiter class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Waiter class which acts as a ConcreteObserver in the Observer
/// design pattern. A waiter will be notified when a TableComponent requires the waiter's assistance.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_WAITER_H
#define COS214_PROJECT_WAITER_H

#include "Observer.h"
#include "TableComposite.h"

class Waiter : public Observer
{
private:
    std::vector<std::string> assignedTableIds;

public:
    Waiter(int id);
    virtual ~Waiter();
    virtual void notify(Customer *customer);
    virtual void notify(TableComposite *table);
    void assignTable(TableComposite *assignedTable);
    void clearAssignedTables();
};

#endif