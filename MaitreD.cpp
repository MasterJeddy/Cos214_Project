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
    this->type = TYPE_MAITRED;

    std::stringstream ss;
    ss << TYPE_MAITRED << id;
    this->id = ss.str();
}

void MaitreD::update()
{
    // this is called when a customer has requested a seat at a table

    // maitreD needs to check if there is space on the floor(in the restaurant)
    // if there is space, sit the customer and remove customer from waiting queue, otherwise tell customer to wait
}

std::string MaitreD::getState()
{
    return this->state;
}
