//===-- COS214_Project/Observer.cpp - Observer class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the notify() function of the Observer class. It provides the means
/// by which the observers are notified regarding a change to the subject.
///
//===----------------------------------------------------------------------===//

#include "Observer.h"

Observer::Observer()
{
}

Observer::~Observer()
{
}

std::string Observer::getId()
{
    return this->id;
}

std::string Observer::getType()
{
    return this->type;
}

std::string Observer::getState()
{
    return this->state;
}