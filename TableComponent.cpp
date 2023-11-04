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
    for (Observer *observer : this->observerList)
    {
        //delete observer;
        observer = nullptr;
    }
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

void TableComponent::setTableState(TableState *tableState)
{
    this->tableState = tableState;
}

TableState* TableComponent::getTableState(){
    return this->tableState;
}
