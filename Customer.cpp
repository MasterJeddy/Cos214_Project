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

Customer::Customer(int id, std::string name)
{
    this->type = TYPE_CUSTOMER;

    std::stringstream idStream;
    idStream << this->type << id;
    this->id = idStream.str();

    this->name = name;
}

Customer::Customer(int id, std::string name, std::vector<Customer *> friends)
{
    this->id = id;
    this->name = name;

    std::vector<Customer *> group = friends;
    group.push_back(this); // add this customer to the group
}

Customer::~Customer()
{
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
