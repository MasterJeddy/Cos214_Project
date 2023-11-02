//===-- COS214_Project/Floor.h - Floor class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Floor class. This is where the customers are seated and
/// managed. Hence the Floor will act as a container that houses the customers, waiters, maitreDs and
// the tables in the restaurant, allowing the different parts of the floor to interact with each other.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_FLOOR_H
#define COS214_PROJECT_FLOOR_H

#include "Waiter.h"
#include "Customer.h"
#include "MaitreD.h"
#include "TableComposite.h"

#include <queue>

class Floor
{
private:
    std::vector<Waiter *> waiters;
    std::queue<Customer *> waitingCustomers;
    std::vector<MaitreD *> maitreDs;
    std::vector<TableComposite *> tables;

    // to keep track of the latest generated ids of the floor objects
    int waiterId;
    int waitingCustomerId;
    int maitreDId;
    int tableId;

public:
    Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<TableComposite *> tables);
    Floor();
    Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<TableComposite *> tables);
    void customerRequestsSeat();
    bool seatCustomer(Customer *customer);

    void dequeueCustomer();

    void addWaiter();
    void addWaitingCustomer();
    void addMaitreD();
    void addTable();

    // getters
    int getTableCount();
    int getMaitreDCount();
    int getWaiterCount();
    int getWaitingCustomerCount();

    // functions for generating ids
    int getAndIncrementWaiterId();
    int getAndIncrementWaitingCustomerId();
    int getAndIncrementMaitreDId();
    int getAndIncrementTableId();
};

#endif