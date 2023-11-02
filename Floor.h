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

public:
    Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<TableComposite *> tables);
    void customerRequestsSeat();
    bool seatCustomer(Customer *customer);

    void dequeueCustomer();

    void addWaiters(std::vector<Waiter *> waiters);
    void addWaitingCustomers(std::queue<Customer *> waitingCustomers);
    void addMaitreDs(std::vector<MaitreD *> maitreDs);
    void addTables(std::vector<TableComposite *> tables);

    void addWaiter(Waiter *waiter);
    void addWaitingCustomer(Customer *waitingCustomer);
    void addMaitreD(MaitreD *maitreDs);
    void addTable(TableComposite *tables); 
    void assignTablesToWaiters();
};

#endif