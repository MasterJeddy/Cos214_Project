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

Floor::Floor()
{
    this->waiterId = 0;
    this->waitingCustomerId = 0;
    this->maitreDId = 0;
    this->tableId = 0;

    // int thisCustomerId = getAndIncrementWaitingCustomerId();

    // create the initial default number of waiters in the game
    for (int i = 0; i < DEFAULT_NO_WAITERS; i++)
    {
        addWaiter();
    }

    // create initial default number of customers in the game
    for (int i = 0; i < DEFAULT_NO_WAITING_CUSTOMERS; i++)
    {
        addWaitingCustomer();
    }

    // create initial default number of maitreDs in the game
    for (int i = 0; i < DEFAULT_NO_MAITREDS; i++)
    {
        addMaitreD();
    }

    // create initial default number of tables in the game
    for (int i = 0; i < DEFAULT_NO_TABLES; i++)
    {
        addTable();
    }
}

void Floor::customerRequestsSeat()
{
    Customer *nextCustomer = this->waitingCustomers.front(); // take next customer from queue

    nextCustomer->request();
}

bool Floor::seatCustomer(Customer *customer)
{

    // if you manage to seat a customer group at a table then you return true
    int size = customer->getGroupSize();
    if (size != 0)
    {
        // loop through the group and seat each person down - once done you may return true
        // check the number of tables needed for this group

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
            if (table->getTableState()->getName() == "Free")
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
            TableComposite *mainTable;

            for (TableComposite *table : tables)
            {
                if (table->getTableState()->getName() == "Free")
                {
                    mainTable = table;
                    break;
                }
            }

            for (TableComposite *table : tables)
            {
                if (table->getTableState()->getName() == "Free" && table != mainTable && numTables != 0)
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
    else if (size == 0)
    {
        // seat the single customer at the table and then return true
        for (TableComposite *table : tables)
        {
            if (table->getTableState()->getName() == "Free") // loop through all the tables and stop when you find a free one
            {
                table->addComponent(customer); // add this customer to the table
                return true;
            }
        }
    }
}

void Floor::dequeueCustomer()
{
    // customer has been successfully sat down, remove them from front of queue
    this->waitingCustomers.pop();
}

void Floor::addWaiter()
{
    int thisWaiterId = getAndIncrementWaiterId();
    Waiter *waiter = new Waiter(thisWaiterId);
    this->waiters.push_back(waiter);
}

void Floor::addWaitingCustomer()
{
    // int thisCustomerId = getAndIncrementWaitingCustomerId();
    // Customer* customer = new Customer();
    // this->waitingCustomers.push(waitingCustomer);
}

void Floor::addMaitreD()
{
    int thisMaitreDId = getAndIncrementMaitreDId();
    MaitreD *maitreD = new MaitreD(thisMaitreDId);
    this->maitreDs.push_back(maitreD);
}

void Floor::addTable()
{
    int thisTableId = getAndIncrementTableId();              // generate a table id for the new table
    TableComposite *table = new TableComposite(thisTableId); // create the table
    this->tables.push_back(table);                           // add table to floor
}

int Floor::getTableCount()
{
    return this->tables.size();
}

int Floor::getMaitreDCount()
{
    return this->maitreDs.size();
}

int Floor::getWaiterCount()
{
    return this->waiters.size();
}

int Floor::getWaitingCustomerCount()
{
    return this->waitingCustomers.size();
}

int Floor::getAndIncrementWaiterId()
{
    int waiterId = this->waiterId;
    this->waiterId = this->waiterId + 1;
    return waiterId;
}

int Floor::getAndIncrementWaitingCustomerId()
{
    int waitingCustomerId = this->waitingCustomerId;
    this->waitingCustomerId = this->waitingCustomerId + 1;
    return waitingCustomerId;
}

int Floor::getAndIncrementMaitreDId()
{
    int maitreDId = this->maitreDId;
    this->maitreDId = this->maitreDId + 1;
    return maitreDId;
}

int Floor::getAndIncrementTableId()
{
    int tableId = this->tableId;
    this->tableId = this->tableId + 1;
    return tableId;
}


void Floor::assignTablesToWaiters(){
    
    //this function will assign tables to the various waiters
    //the tables will be split as evenly as possible between 
    //the various waiters
    //count the number of tables and waiters 
    int numTables = getTableCount();
    int numWaiters = getWaiterCount();

    //clear all of the old assigned tables (if any) for all 
    // of the waiters 
    for(Waiter* waiter: waiters){
        waiter->clearAssignedTables();
    }



    if (numTables>numWaiters)
    {
        //this calculation will only run when the number of Tables is greater than the number of Waiters
        int numTablesPerWaiter = numTables/numWaiters;      //this answer is rounded down (java)
        //loop through each waiter and assign numTablesPerWaiter Tables to each waiter and the last waiter gets all the leftover tables
        

        
            //this will assign the tables as evenly as possible to 
            //each waiter 

            //the first n-1 waiters will get numTablesPerWaiter 
            //all of those waiters will get the same number of Tables
            //assigned to them however the last one will take the 
            //leftover tables which will either be the same or slightly more

            for(int i = 0; i<waiters.size(); i++){

             

            //this is the first n-1 waiters
                if(i!=waiters.size()-1){
                    for(int j = i*numTablesPerWaiter; j<numTablesPerWaiter*(i+1); j++){
                    waiters[i]->assignTable(tables[j]);
                }
                }
                //the last waiter 
                else if(i == waiters.size()-1){
                    //assign the last waiter all of the leftover tables
                    //the number of leftover tables is just numTables - (waiters-1)*numTablesPerWaiter
                    int leftoverTables = numTables - (waiters.size()-1)*(numTablesPerWaiter);
                    for(int x = i*numTablesPerWaiter; x<(i*numTablesPerWaiter)+leftoverTables; x++){
                    waiters[i]->assignTable(tables[x]);
                    }
                }

            }


        
        
        
    }

    else if(numTables == numWaiters) {
        //the case where number of tables and waiters are the same

            //this case is easy as each waiter will get 
            //one table assigned to them 
            for (int i = 0; i<waiters.size(); i++)
            {
                waiters[i]->assignTable(tables[i]);
            }
            


    }

    else{
        //This is the case where the 
        //number of waiters is greater than the number 
        // of tables and therefore not all of the waiters
        // will receive a table. Some will have to be
        // on 'stand-by' and therefore will not be responsible
        // for any tables, at least until no new tables are added
        // by the player.

        for(int i = 0; i<tables.size(); i++){       //only one waiter per table 
            waiters[i]->assignTable(tables[i]);
        }

        //the rest of the waiters will be on standy 
        //for the given moment
    }

}