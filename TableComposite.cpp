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

TableComposite::TableComposite(int id, int waiterId)
{
    // id was made a string such that we do not end up with a case where TableComposite and Customer do not end up with the same Id. We will append a special character
    // for each respective object in order to help avoid any sort of confusion later down the line.
    std::string tempy = to_string(id) + "TC";
    this->id = tempy;
    this->waiterId = waiterId;
}

TableComposite::addComponent(TableComponent component)
{
    children.push_back(component);
}

TableComposite::removeComponent(TableComponent component)
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

TableComponent TableComposite::getChild(int id)
{
    for (TableComponent child : children)
    {
        if (child->getId() == id)
        {
            return child;
        }
        return null;
    }
}

int TableComposite::getCapacity()
{
    return this->maxCapacity;
}

void TableComposite::setCapacity(int capacity)
{
    this->maxCapacity = capacity;
}

TableState TableComposite::getTableState()
{
    return this->tableState;
}

void TableComposite::setTableState(TableState *tableState)
{
    this->tableState = tableState;
}

void TableComposite::request()
{
    for(Observer* observer: ObserverList){
        //loop through the observer list
        if (observer->getType().equals("Waiter") && observer->getId() == waiterId)
        {
            //notify this waiter
            observer->update();
            break;
        }
        
    }
}

void TableComposite::requestBill()
{
    //notify the waiter then pass in the bill so that the waiter can create a bill
    for(Observer* observer: ObserverList){
        //loop through the observer list
        if (observer->getType().equals("Waiter") && observer->getId() == waiterId)
        {
            //notify this waiter
            //change the state to bill
            tableState->proceed();

            observer->update();
            break;
        }
        
    }
}

std::String TableComposite::getId()
{
    return this->id;
}


void TableComposite::attachObserver(Observer* observer){
    observerList->push_back(observer);
}

void TableComposite::detachObserver(Observer* observer){
     std::vector<Observer *>::iterator miki = observerList.begin();
    for (miki; miki < ObserverList.end(); miki++)
    {
        if ((*miki)->getId() == component->getId())
        {
            children.erase(miki);
            break;
        }
    }
}