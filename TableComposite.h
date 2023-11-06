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
#include "BillComponent.h"
#include "Order.h"
#include "BillComposite.h"
#include "SubBill.h"

#include "Constants.h"

#include <sstream>

class Waiter;

class TableState;

class TableComposite : public TableComponent
{
private:
    std::vector<TableComponent *> children;
    std::string waiterId;
    int maxCapacity;
    TableState *tableState;
    BillComponent *bill;
    std::vector<Order *> orders;
    int numOfFinishedOrders;

public:
    /// \brief Creates a table composite with id passed in.
    /// Initialises the state to the free state and sets 
    /// the type of the component.
    /// \param id Id of the table that will be created.
    TableComposite(int id);
    /// \brief Destructor for the table composite.
    virtual ~TableComposite();
    /// \brief Adds a component to the vector of children.
    /// \param component Either a customer of another table.
    void addComponent(TableComponent *component);
    /// \brief Removes a component from the vector of children.
    /// \param component Either a customer of another table.
    void removeComponent(TableComponent *component);
    /// \brief Notifies the waiter that a bill has been requested.
    /// Transitions the state to 'Bill'.
    void requestBill();

    // getters
    
    /// \brief Gets the max capacity of the table
    /// We assumed that each table will have a max 
    /// capacity of four (they are square)
    /// \return Returns the max capacity.
    int getCapacity();
    /// \brief gets the child with the passed in id
    /// \param id Id of the child that is being searched for.
    /// \return Pointer to the child that was searched for.
    TableComponent *getChild(std::string id);
    /// \brief Returns the current state of the table.
    /// \return Returns a TableState pointer of the state.
    virtual TableState *getTableState();
    /// \brief Returns a string of the Ids of combined tables
    /// (if any), as well as the customers that have seated 
    /// at this table.
    /// \return Returns a formatted string used in our UI.
    std::string getLabel();
    /// \brief Gets all the children.
    /// \return Returns a vector of all the children of the TableComposite.
    std::vector<TableComponent *> getChildren();


    /// \brief Creates a bill, then returns the total of the respective bill
    /// \return Returns the total price of the respective bill that was created.
    virtual double getPayment();
    /// \brief Checks if a table is contained within another table.
    
    /// \return Returns a boolean indicating if a table is combined with another table.
    bool isContainedInAnotherTable();

    // setters

    /// \brief Sets the max capacity of a table.
    /// This function will be called every time we 
    /// combine tables as this number will change every 
    /// time we combine tables with each other. 
    /// This indicates the maximum number of customers that
    /// may be seated at a specific table.
    /// \param capacity This is the passed in capacity.
    void setMaxCapacity(int capacity);
    /// \brief Changes the state of the table to the passed in parameter.
    /// \param tableState Next state to change the table to.
    virtual void setTableState(TableState *tableState);
    /// \brief This function will assign the passed in waiter to this table.
    /// \param waiter This is the waiter that will be responsible for this table.
    void assignWaiter(Waiter *waiter);

    // observer dp related functions

    /// \brief This function will attach an observer to the ObserverList.
    /// This observer will watch this table. 
    /// \param observer This is the observer that will watch this table.
    virtual void attachObserver(Observer *observer);
    /// \brief This will detach an observer from the ObserverList.
    
    /// \param observer This is the observer that will be removed.
    virtual void detachObserver(Observer *observer);
    /// \brief Notifies a waiter observer that a table requires the waiters service.
    virtual void request();

    // accept or reject the service of a waiter
    
    /// \brief Simulate accepting the service of a waiter once they arrive at your table.
    /// \return Returns the random boolean indicating whether the service was accepted or rejected.
    bool acceptOrReject();
    // returns an order
    // calls the proceed() function

    /// \brief Creates a single order for all the customers that are sitting at the table.
    /// \return Returns the order that was created for the table.
    Order* order(); // may also add a complexOrder function
    // return a slightly more complex order

    /// \brief Creates a vector of  slightly more complex orders for all the customers that are sitting at the table.
    /// \return Returns a vector of slightly more complex orders from the table.
    Order *complexOrder();
    // returns a complex order with quantities up to 20

    /// \brief Creates a vector of very complex orders for all the customers that are sitting at the table.
    /// \return Returns a vector of very complex orders from the table.
    Order *ultraComplexOrder();
    // rejected service of the waiter
    // calls the hold() function
    
    /// \brief Handles a specific case for a table. Transitions the state accordingly.
    void rejectedService();
    /// \brief Simluates the customers eating their food.
    /// \param order This is the order that was delivered to the table.
    void eat(Order *order);
    /// \brief This makes the IO interface a friend class of TableComposite.
    friend class IOInterfaceGUI;
};
#include "Waiter.h"
#endif