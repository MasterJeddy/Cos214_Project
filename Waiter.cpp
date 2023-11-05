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
#include "Kitchen.h"
#include "Clock.h"

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
    Kitchen::getInstance()->detach(this);
    this->assignedTableIds.clear();
}

void Waiter::notify(Customer *customer)
{
}

void Waiter::takeOrderToFloor(Order *finishedOrder)
{
    // if order has really been finished
    if (finishedOrder != nullptr)
    {
        // at this point order has been finished
        Floor::instance()->takeOrderToTable(finishedOrder);
    }
}

void Waiter::notify(TableComposite *table)
{
    // called when a table requires the waiter's assistance
    this->state = "BUSY";

    // if state of table is WaitingOnWaiter then check if table is ready to order or not
    if (table->getTableState()->getName() == "WaitingOnWaiter")
    {
        bool tableReady = table->acceptOrReject();

        if (tableReady)
        {
            Order *tableOrder = table->order(); // get order of table
            bool result = Kitchen::getInstance()->addOrder(tableOrder); // now pass order to kitchen
            // now attach this waiter as an observer to the kitchen
            Kitchen::getInstance()->attach(this);
        }
        else
        {
            // go back since table is not yet ready to order
            // change the state of the table back to busy
            table->getTableState()->hold(table);
        }
    }
    // else if state of table is bill, then bill the customers
    else if (table->getTableState()->getName() == "Bill")
    {
        if (Clock::instance().getTime(table->getId()) >2){
          double totalBill = table->getPayment();
          Floor::instance()->addSalesRevenue(totalBill);
          Clock::instance().removeTime(table->getId());
        }


    }
    this->state = "FREE";
}

void Waiter::assignTable(TableComposite *assignedTable)
{
    this->assignedTableIds.push_back(assignedTable->getId());

    // also assign this waiter to the passed in table
    assignedTable->assignWaiter(this);
}

void Waiter::clearAssignedTables()
{
    this->assignedTableIds.clear();
}

bool Waiter::isResponsibleForThisTable(std::string tableId)
{
    // this function will loop through all of the
    // assigned TableIds and return whether this
    // waiter is responsible for the tableId that
    // was passed in as a parameter
    for (std::string tempId : this->assignedTableIds)
    {
        if (tempId == tableId)
        {
            return true;
        }
    }
    return false;
}