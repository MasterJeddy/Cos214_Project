//===-- COS214_Project/Waiter.cpp - Waiter class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Waiter class functions as well as the methods declared
/// by its parent class, more specifically the request() method where a customer can request to be seated
/// at a table..
///
//===----------------------------------------------------------------------===//

#include "Waiter.h"

Waiter::Waiter(int id)
{
    // set the type of this ConcreteObserver
    this->type = TYPE_WAITER;

    // set the id of this waiter
    std::stringstream ss;
    ss << this->type << id;
    this->id = ss.str();

    // set the default state for waiter
    this->state = "FREE";
}

Waiter::~Waiter()
{
    // clear vector of tables ids assigned to this waiter
    this->assignedTableIds.clear();
}

void Waiter::notify(Customer *customer)
{
}

void Waiter::notify(TableComposite *table)
{
    // called when a table requires the waiter's assistance
    this->state = "BUSY";

    bool tableReady = table->acceptOrReject();

    if(tableReady){
        
    }
    else{

    }

    this->state = "FREE";
}

void Waiter::assignTable(TableComposite *assignedTable)
{
    this->assignedTableIds.push_back(assignedTable->getId());

    // also assign this waiter to the passed in table
    assignedTable->assignWaiter(this->id);
}

void Waiter::clearAssignedTables()
{
    this->assignedTableIds.clear();
}
