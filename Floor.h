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
    /// \brief Gets the only instance of floor
    /// \return Returns only instance of floor
    static Floor *instance();
    /// @brief Takes the customer at the front of the queue and calls the request function.
    /// Notifies MaitreD that the customer has requested for a seat.
    void requestSeat();
    /// @brief Adds a customer to a free table. 
    /// @param customer the customer that will be seated at the table
    /// @return boolean representing whether customer was successfully seated
    bool seatCustomer(Customer *customer);
    /// @brief Removes the customer at the front of the queue.
    void dequeueCustomer();
    /// @brief Adds revenue to our total sales revenue. This gets done every time a bill is settled.
    /// @param totalBill This is the price of the total bill that was paid.
    void addSalesRevenue(double totalBill);
    /// @brief creates a new waiter and adds this to the list of waiters on the floor
    void addWaiter();
    /// @brief Creates a customer with a randomly sized group. Adds to the waiting customer queue.
    void addWaitingCustomer();
    /// @brief Adds a MaitreD to the list of MaitreD's on the floor.
    void addMaitreD();
    /// @brief creates a table.
    void addTable();
    /// @brief This function assigns tables to waiters as evenly as possible.
    void assignTablesToWaiters();

    /// @brief removes the waiter with the passed in id
    /// @param id is the id of the waiter that will be removed
    void removeWaiter(std::string id);
    /// @brief removes a waiting customer from the queue with the passed in id 
    /// @param id of the customer that will be removed from the queue
    void removeWaitingCustomer(std::string id);
    /// @brief removes the MaitreD with the passed in id from the list of MaitreD's.
    /// @param id Id of the MaitreD that is to be removed from the list.
    void removeMaitreD(std::string id);
    /// @brief Removes a table with the passed in id.
    /// @param id Id of the table that will be removed from the floor.
    void removeTable(std::string id);


    // getters

    /// @brief Gets a count of the tables.
    /// @return Number of tables on the floor.
    int getTableCount();
    /// @brief Gets a count of the MaitreDs.
    /// @return Number of MaitreDs on the floor.
    int getMaitreDCount();
    /// @brief Gets a count of the waiters.
    /// @return Number of waiters on the floor.
    int getWaiterCount();
    /// @brief Gets a count of the customers.
    /// @return Number of customers on the floor.
    int getWaitingCustomerCount();

    /// @brief Returns the first free MaitreD.
    /// @return Returns a pointer to the free MaitreD.
    MaitreD *getRandomMaitreD();

    /// @brief Returns a vector of waiters on the floor.
    /// @return A vector of waiters on the floor.
    std::vector<Waiter *> getWaiters();
    /// @brief Returns a vector of waiting customers in the queue.
    /// @return A vector of waiting customers in the queue.
    std::queue<Customer *> getWaitingCustomers();
    /// @brief Returns a vector of MaitreDs on the floor.
    /// @return A vector of MaitreD's on the floor.
    std::vector<MaitreD *> getMaitreDs();
    /// @brief Returns a vector of tables on the floor.
    /// @return A vector of tables on the floor.
    std::vector<TableComposite *> getTables();

    /// @brief Used by the waiter to take an order from the kitchen to the table.
    /// @param order This is the finished order from kitchen.
    void takeOrderToTable(Order *order);
    /// @brief Resets the number of objects in the floor to the default values.
    /// Resets to the initial state.
    void reset();
};
#include "Waiter.h"
#include "MaitreD.h"

#endif