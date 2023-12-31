//===-- COS214_Project/TableComponent.cpp - TableComponent class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the virtual destructor definition for the TableComponent class. The destructor has to
/// be defined here(even if empty) since this class is an abstract class.
///
//===----------------------------------------------------------------------===//

#include "TableComponent.h"

TableComponent::TableComponent()
{
}

TableComponent::~TableComponent()
{
    // clear observerList, memory cleanup will be done by floor class
    this->observerList.clear();
}

std::string TableComponent::getId()
{
    return this->id;
}

std::string TableComponent::getType()
{
    return this->type;
}
