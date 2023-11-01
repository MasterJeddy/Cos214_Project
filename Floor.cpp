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

Floor::Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<Table *> tables)
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

    this->waitingCustomers.pop(); // remove this customer from queue
}

bool Floor::seatCustomer(Customer* customer){
    
    //if you manage to seat a customer group at a table then you return true
    if (customer->getGroupSize()>1)
    {
        //loop through the group and seat each person down - once done you may return true
        Customer* customers = customer->getGroup();     //get the group of customers
        for(Customer* customer: customers){             //loop through all of the customers
            customer
        }
    }
    else if(customer->getGroupSize()==1){
        //seat the single customer at the table and then return true

    }
    
}

