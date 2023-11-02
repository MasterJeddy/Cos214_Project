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
#include "Order.h"  

class TableComposite : public TableComponent
{
private:
    std::vector<TableComponent *> children;
    std::string waiterId;
    int maxCapacity;
    TableState *tableState;
    BillComponent *bill;

public:
    TableComposite(int id);
    void addComponent(TableComponent *component);
    void removeComponent(TableComponent *component);
    void requestBill();

    // getters
    int getCapacity();
    TableComponent *getChild(std::string id);
    TableState *getTableState();

    // setters
    void setMaxCapacity(int capacity);
    void setTableState(TableState *tableState);
    void assignWaiter(std::string waiterId);

    // observer dp related functions
    virtual void attachObserver(Observer *observer);
    virtual void detachObserver(Observer *observer);
    virtual void request();

    //accept or reject the service of a waiter 
    bool acceptOrReject();
    //returns an order
    //calls the proceed() function
    Order* order();     //may also add a complexOrder function 
    //return a slightly more complex order
    Order* complexOrder();
    //returns a complex order with quantities up to 20 
    Order* ultraComplexOrder();
    //rejected service of the waiter
    //calls the hold() function
    void rejectedService();
};

#endif