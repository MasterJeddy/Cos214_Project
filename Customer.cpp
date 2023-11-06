//===-- COS214_Project/Customer.cpp - Customer class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Customer class functions as well as the methods declared
/// by its parent class, more specifically the request() method where a customer can request to be seated
/// at a table..
///
//===----------------------------------------------------------------------===//

#include "Customer.h"

Customer::Customer(int id)
{
    this->alone = true;

    this->type = TYPE_CUSTOMER;

    std::stringstream idStream;
    idStream << this->type << id;
    this->id = idStream.str();
}

Customer::~Customer()
{
    // delete all customer pointers in the group vector that are not equal to this customer object
    for (Customer *customer : this->group)
    {
        if (customer != this)
        {
            delete customer;
            customer = NULL;
        }
    }
    this->group.clear(); // finally clear the vector of customers
}

void Customer::attachObserver(Observer *observer)
{
    // add the passed in observer to the list of observers
    this->observerList.push_back(observer);
}

void Customer::detachObserver(Observer *observer)
{
    for (std::vector<Observer *>::iterator i = this->observerList.begin(); i < this->observerList.end(); i++)
    {
        if ((*i)->getId() == observer->getId())
        {
            this->observerList.erase(i);
            return;
        }
    }
}

void Customer::request()
{
    for (std::vector<Observer *>::iterator iter = this->observerList.begin(); iter < this->observerList.end(); iter++)
    {

        // find a ConcreteObserver that is a maitreD and that is currently free and notify them of request
        if ((*iter)->getType() == TYPE_MAITRED && (*iter)->getState() == "FREE")
        {
            (*iter)->notify(this);
            return;
        }
    }

    // if this point is reached, it means all the maitreDs are curently busy at the moment
}

int Customer::getGroupSize()
{
    return this->group.size();
}

std::vector<Customer *> Customer::getGroup()
{
    return this->group;
}

bool Customer::isAlone()
{
    return this->alone;
}

void Customer::addToGroup(Customer *frend)
{
    this->group.push_back(frend);
    alone = false;
}