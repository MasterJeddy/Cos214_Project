#include "MaitreD.h"
//===-- COS214_Project/MaitreD.cpp - MaitreD class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of functions that a MaitreD is responsible for, like checking the
/// restaurant for space and then making a decision on whether to sit the customer at a table or have them wait.
/// A maitreD will be notified when a customer request for a seat a table.
///
//===----------------------------------------------------------------------===//
MaitreD::MaitreD(int id)
{
    // set the type of this ConcreteObserver
    this->type = TYPE_MAITRED;

    // set the id of this maitreD
    std::stringstream ss;
    ss << this->type << id;
    this->id = ss.str();

    // set the default state for maitreD
    this->state = "FREE";
}

void MaitreD::notify(TableComponent* component)
{
    // change stat of this maitreD to BUSY
    this->state = "BUSY";

    // this is called when a customer has requested a seat at a table

    // maitreD needs to check if there is space on the floor(in the restaurant)
    // if there is space, sit the customer and remove customer from waiting queue, otherwise tell customer to wait

    bool success = this->floor->seatCustomer(component);

    if (success)
    {
        // customer was successfully sat down at table, remove them from queue
        this->floor->dequeueCustomer(); // remove this customer from queue
    }
    else
    {
        // there was no space in restaurant, keep customer in queue
    }

    // change state of maitreD back to FREE
    this->state = "FREE";
}
