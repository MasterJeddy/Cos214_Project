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
    // this->ty
    this->id = id;
    this->name = name;
}

Customer::Customer(int id, std::string name, std::vector<Customer *> friends)
{
    this->id = id;
    this->name = name;

    std::vector<Customer *> group = friends;
    group.push_back(this); // add this customer to the group
}

void Customer::attachObserver(Observer *observer)
{
    // add the passed in observer to ythe list of observers
    this->observerList.push_back(observer);
}

void Customer::detachObserver(Observer *observer)
{
    for (std::vector<Observer *>::iterator i = this->observerList.begin(); i < this->observerList.end(); i++)
    {
        if ((*i)->getId() == observer->getId())
        {
            this->observerList.erase(i);
            break;
        }
    }
}

void Customer::request()
{
    // thi
}
