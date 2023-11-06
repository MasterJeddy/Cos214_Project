//===-- COS214_Project/Waiter.h - Waiter class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Waiter class which acts as a ConcreteObserver in the Observer
/// design pattern. A waiter will be notified when a TableComponent requires the waiter's assistance.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_WAITER_H
#define COS214_PROJECT_WAITER_H

#include "Observer.h"
#include "TableComposite.h"
#include "Floor.h"

class Waiter : public Observer
{
private:
    std::vector<std::string> assignedTableIds;

public:
    /// \brief sets the id of the waiter, sets initial state to FREE and sets type of observer that it is
    /// \param id integer that is used to create the id of the waiter
    Waiter(int id);

    /// \brief clears the list of tables assigned to this waiter
    virtual ~Waiter();

    /// \brief called when a customer requests a seat
    /// \param customer the customer requesting a seat
    virtual void notify(Customer *customer);

    /// \brief called when a table requests the waiter's assistance
    /// \param table the table that is currently requesting assistance
    virtual void notify(TableComposite *table);

    /// \brief assigns a table to this waiter
    /// \param assignedTable the table that this waiter is going to be responsible for
    void assignTable(TableComposite *assignedTable);

    /// \brief clears the list of tables that were assigned to this waiter
    void clearAssignedTables();

    /// \brief receives finished order from kitchen and take it to the floor
    /// \param finishedOrder the finished order from kitchen that need to be taken to floor
    void takeOrderToFloor(Order *finishedOrder);

    friend class IOInterfaceGUI;

    /// \brief checks if this waiter is responsible for the table with the passed in id
    /// \param tableId teh id of the table to check against
    /// \return true if waiter is responsible for the table, otherwise false
    bool isResponsibleForThisTable(std::string tableId);

    /// \brief check all the tables assigned to this waiter and display the table ids
    /// \return a string that displays the id of the state and the list of table ids of tables assigned to this waiter
    std::string getLabel();
};

#endif