//===-- COS214_Project/TableComposite.h - TableComposite class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TableComposite class which acts here as the
/// the Composite participant in the Composite design pattern. For example when taking an order, the waiter will interact with an object 
/// from this class. This class implements the interface provided by the TableComponent interface. It contains either children that are
/// either composites(Table objects) or leaves (Customer objects). This allows for us to add tables to each other (to make space for larger groups),
/// and Customer objects may be added to tables. 
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLECOMPOSITE_H
#define COS214_PROJECT_TABLECOMPOSITE_H
#include "TableComponent.h"
#include "TableState.h"
#include "BillComponent.h"

class TableComposite: public TableComponent
{
    private: 
    std::vector<TableComponent*> children;
    std::String id; 
    int maxCapacity;
    TableState* tableState;
    BillComponent bill;
    int waiterId;

    public: 
    void addComponent(TableComponent component);
    void removeComponent(TableComponent component);
    TableComponent getChild(int id);
    int getCapacity();
    void setCapacity(int capacity);
    TableState getTableState();
    void setTableState(TableState* tableState);
    void request();
    void requestBill();
    TableComposite(int id, int waiterId);
    String getId();
    void attachObserver(Observer* observer);
    void detachObserver(Observer* observer);

};

#endif