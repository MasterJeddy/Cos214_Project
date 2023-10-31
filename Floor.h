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
#include "Table.h"

#include <queue>

class Floor
{
private:
    std::vector<Waiter *> waiters;
    std::queue<Customer *> waitingCustomers;
    std::vector<MaitreD *> maitreDs;
    std::vector<Table *> tables;

public:
    Floor(std::vector<Waiter *> waiters, std::queue<Customer *> waitingCustomers, std::vector<MaitreD *> maitreDs, std::vector<Table *> tables);
    void customerRequestsSeat();
    bool spaceAvailable();
    void seatCustomer();
};

#endif