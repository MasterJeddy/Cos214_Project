//===-- COS214_Project/TableComposite.cpp - TableComposite class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Table class specific functions as well as the functions
/// declared by its parent class TableComponent, for example the add() function where a component can
/// be added to a table.
///
///
//===----------------------------------------------------------------------===//

#include "TableComposite.h"

TableComposite::TableComposite(int id)
{
    // id was made a string such that we do not end up with a case where TableComposite and Customer do not end
    // up with the same Id. We will append a special character for each respective object in order to help avoid
    // any sort of confusion later down the line.
    this->type = TYPE_TABLECOMPOSITE;

    this->waiterId = ""; // this table has not yet been assigned to a waiter

    std::stringstream idStream;
    idStream << this->type << id;
    std::string tempy = idStream.str();
    this->id = tempy;

    // set the default max capacity of the table to 4 - one table can host 4 people
    this->maxCapacity = 4;
}

void TableComposite::addComponent(TableComponent *component)
{
    int counter = 1; // this will count the number of tables we have combined - starts off at 1 because the parent
                     // table doesn't count as a child
    //  and is therefore not part of the children vector
    children.push_back(component);
    std::vector<TableComponent *>::iterator miki = children.begin();
    for (miki; miki < children.end(); miki++)
    {
        if ((*miki)->getType() == TYPE_TABLECOMPOSITE)
        {
            counter++;
        }
    }
    // maxCapacity is equal to 4 + 2*(number of tables - 1)
    this->maxCapacity = 4 + 2 * (counter - 1);
}

void TableComposite::removeComponent(TableComponent *component)
{

    std::vector<TableComponent *>::iterator miki = children.begin();
    for (miki; miki < children.end(); miki++)
    {
        if ((*miki)->getId() == component->getId())
        {
            children.erase(miki);
            break;
        }
    }
}

TableComponent *TableComposite::getChild(std::string id)
{
    for (TableComponent *child : children)
    {
        if (child->getId() == id)
        {
            return child;
        }
        return NULL;
    }
}

int TableComposite::getCapacity()
{
    return this->maxCapacity;
}

void TableComposite::setMaxCapacity(int capacity)
{
    this->maxCapacity = capacity;
}

TableState *TableComposite::getTableState()
{
    return this->tableState;
}

void TableComposite::setTableState(TableState *tableState)
{
    this->tableState = tableState;
}

void TableComposite::assignWaiter(std::string waiterId)
{
    std::stringstream waiterIdStream;
    waiterIdStream << TYPE_WAITER << waiterId;
    std::string tempy2 = waiterIdStream.str();
    this->waiterId = tempy2;
}

void TableComposite::request()
{
    for (Observer *observer : observerList)
    {
        // loop through the observer list
        if (observer->getType() == TYPE_WAITER && observer->getId() == waiterId)
        {
            // notify this waiter
            observer->notify(this);
            break;
        }
    }
}

void TableComposite::requestBill()
{
    // notify the waiter then pass in the bill so that the waiter can create a bill
    for (Observer *observer : observerList)
    {
        // loop through the observer list
        if (observer->getType() == TYPE_WAITER && observer->getId() == waiterId)
        {
            // notify this waiter
            // change the state to bill
            tableState->proceed();

            observer->notify(this);
            break;
        }
    }
}

void TableComposite::attachObserver(Observer *observer)
{
    observerList.push_back(observer);
}

void TableComposite::detachObserver(Observer *observer)
{
    std::vector<Observer *>::iterator miki = observerList.begin();
    for (miki; miki < observerList.end(); miki++)
    {
        if ((*miki)->getId() == observer->getId())
        {
            observerList.erase(miki);
            break;
        }
    }
}