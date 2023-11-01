//===-- COS214_Project/Floor.cpp - Floor class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of certain functions in the floor class that are used by the
/// restaurant stuff, for example the function to check for space in the restaurant. This function is used
/// by the maitreD when a customer has requested for a table to first check if there are any free tables.
///
//===----------------------------------------------------------------------===//

#include "Floor.h"

Floor::Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<TableComposite *> tables)
{
    this->waiters = waiters;
    this->waitingCustomers = waitingCustomers;
    this->maitreDs = maitreDs;
    this->tables = tables;
}

void Floor::customerRequestsSeat()
{
    Customer *nextCustomer = this->waitingCustomers.front(); // take next customer from queue

    nextCustomer->request();
}

void Floor::dequeueCustomer()
{
    // customer has been successfully sat down, remove them from front of queue
    this->waitingCustomers.pop();
}

bool Floor::spaceAvailable(Customer *customer)
{
    // customers are in a group and we need to check if there is space available for them within the restaurant
    //  we do this by checking the various 'free' tables and counting the number of spots available
    //  and checking to see whether this value is larger than or equal to the group size
}
