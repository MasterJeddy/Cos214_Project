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

#include "Customer.h"

#include "TableComposite.h"
#include <queue>

class Waiter;
class MaitreD;

class Floor
{
private:
    static Floor *onlyInstance_;

    double salesRevenue;

    std::vector<Waiter *> waiters;
    std::queue<Customer *> waitingCustomers;
    std::vector<MaitreD *> maitreDs;
    std::vector<TableComposite *> tables;

    // to keep track of the latest generated ids of the floor objects
    int waiterId;
    int waitingCustomerId;
    int maitreDId;
    int tableId;

    // functions for generating ids
    int getAndIncrementWaiterId();
    int getAndIncrementWaitingCustomerId();
    int getAndIncrementMaitreDId();
    int getAndIncrementTableId();

protected:
    Floor();
    // Floor(const Floor &);
    // Floor &operator=(const Floor &);
    ~Floor();

public:
    static Floor *instance();

    void requestSeat();
    bool seatCustomer(Customer *customer);

    void dequeueCustomer();

    void addSalesRevenue(double totalBill);

    void addWaiter();
    void addWaitingCustomer();
    void addMaitreD();
    void addTable();
    void assignTablesToWaiters();

    void removeWaiter(std::string id);
    void removeWaitingCustomer(std::string id);
    void removeMaitreD(std::string id);
    void removeTable(std::string id);

    void updateObserved();

    // getters
    int getTableCount();
    int getMaitreDCount();
    int getWaiterCount();
    int getWaitingCustomerCount();

    MaitreD *getRandomMaitreD();

    std::vector<Waiter *> getWaiters();
    std::queue<Customer *> getWaitingCustomers();
    std::vector<MaitreD *> getMaitreDs();
    std::vector<TableComposite *> getTables();

    void takeOrderToTable(Order *order);
};
#include "Waiter.h"
#include "MaitreD.h"

#endif