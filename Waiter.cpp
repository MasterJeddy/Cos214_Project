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

Waiter::Waiter(int id)
{
    // set the type of this ConcreteObserver
    this->type = TYPE_WAITER;

    // set the id of this maitreD
    std::stringstream ss;
    ss << this->type << id;
    this->id = ss.str();

    // set the default state for maitreD
    this->state = "FREE";
}

void Waiter::notify()
{
    this->state = "BUSY";







    this->state = "FREE";
}
