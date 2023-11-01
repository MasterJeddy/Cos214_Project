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

void Floor::addWaiters(std::vector<Waiter *> waiters)
{
     for (int i = 0; i < waiters.size(); i++)
    {
        this->waiters.push_back(waiters[i]);
    }
}

void Floor::addWaitingCustomers(std::queue<Customer *> waitingCustomers)
{
     for (int i = 0; i < waitingCustomers.size(); i++)
    {
        this->waitingCustomers.push_back(waitingCustomers[i]);
    }
}

void Floor::addMaitreDs(std::vector<MaitreD *> maitreDs)
{
     for (int i = 0; i < maitreDs.size(); i++)
    {
        this->maitreDs.push_back(maitreDs[i]);
    }
}

void Floor::addTables(std::vector<TableComposite *> tables)
{
    for (int i = 0; i < tables.size(); i++)
    {
        this->tables.push_back(tables[i]);
    }
}

void Floor::addTable(TableComposite *table)
{
    this->tables.push_back(table);
}

bool Floor::seatCustomer(Customer *customer)
{

    // if you manage to seat a customer group at a table then you return true
    if (customer->getGroup() != null)
    {
        // loop through the group and seat each person down - once done you may return true
        // check the number of tables needed for this group

        int size = customer->getGroupSize();
        int idealSize;
        if (size % 2 == 0)
        {
            idealSize = size;
        }
        else
        {
            idealSize++;
        }
        // idealSize is just an integer that is used to calculate the number of tables that we would need to combine for this group
        // easier to calculate when the number is even as the function goes up in two's i.e 4, 6, 8, 10, 12.
        // For a group of 5 we will simply 'increment' to 6 and then calculate the number of tables that we would need to combine
        //  for this group which in this case would be 2 because 6 = 4 + 2(NumTables - 1)
        //  Solve for NumTables we get:
        //  NumTables = (6-2)/2 = 4/2 = 2.
        //  Therefore we need two tables to fit this group of 5 customers.
        //  The general formula for NumTables is the following:
        //  NumTables = (idealSize-2)/2

        int numTables = (idealSize - 2) / 2;

        int numFreeTables = 0; // this is a counter for the number of Tables that are in the 'Free' state

        for (TableComposite *table : tables)
        {
            if (table->getTableState()->getName().equals("Free"))
            {
                numFreeTables++;
            }
        }

        // if the number of free tables is greater than the numTables value then we will be able to seat this group of customers
        //  we will need to combine these tables together and then once we have combined them we will then be able to add
        //  all of these customers as leaves
        //  once the customers have settled their bill and have finished eating we will have to separate these tables again
        //  we will loop through the children vector and remove them one by one

        if (numFreeTables >= numTables)
        {
            // we are able to seat this group of customers
            for (TableComposite *table : tables)
            {
                if (table->getTableState()->getName().equals("Free"))
                {
                    TableComposite *mainTable = table;
                    break;
                }
            }

            for (TableComposite *table : tables)
            {
                if (table->getTableState()->getName().equals("Free") && table != mainTable && numTables != 0)
                {
                    mainTable->addComponent(table); // combine all the tables together
                    numTables--;
                }
            }

            // once all the tables have been combined - we add the customers
            for (Customer *customer : customer->getGroup())
            {
                mainTable->addComponent(customer);
            }

            // once the bill is settles the TableComposite will call a function to clear the children and 'revert' back to the
            // original position of having separate tables that are not combined together
        }
    }
    else if (customer->getGroup() == null)
    {
        // seat the single customer at the table and then return true
        for (TableComposite *table : tables)
        {
            if (table->getTableState()->getName().equals("Free")) // loop through all the tables and stop when you find a free one
            {
                table->addComponent(customer); // add this customer to the table
                return true;
            }
        }
    }
}
