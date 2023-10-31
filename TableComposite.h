//===-- COS214_Project/TableComposite.h - TableComposite class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TableComposite class which acts here as the
/// the Composite participant in the Composite design pattern. For example when taking an order, the waiter will interact with an object 
/// from this class.
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLECOMPOSITE_H
#define COS214_PROJECT_TABLECOMPOSITE_H
#include "TableComponent.h"
#include "TableState.h"
#include "BillComponent.h"

class TableComposite: public TableComponent
{
    private: 
    TableComponent* children;
    int id; 
    int maxCapacity;
    TableState* tableState;
    BillComponent bill;

    public: 
    void add(TableComponent component);
    void remove(TableComponent component);
    TableComponent getChild(int id);
    int getCapacity();
    void setCapacity();
    TableState getTableState();
    void request();
    void requestBill();
    TableComposite();

};

#endif