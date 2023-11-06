//===-- COS214_Project/TableComponent.h - TableComponent class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TableComponent class which acts here as the
/// the Component participant in the Composite design pattern. This class provides the interface with
/// which the clients interact. For example when taking an order, the waiter will interact with an object that
/// implements this interface.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TABLECOMPONENT_H
#define COS214_PROJECT_TABLECOMPONENT_H

#include "Observer.h"
#include <vector>
#include <string>

#include "TableState.h"

class TableState;
class TableComponent
{
protected:
    std::string id;
    std::string type;
    std::vector<Observer *> observerList;

public:
    /// \brief Constructor for the TableComponent.
    TableComponent();

    /// \brief Destructor for the TableComponent.
    virtual ~TableComponent();

    /// \brief Gets the id of the TableComponent.
    /// \return Returns the id as a string.
    std::string getId();
    
    /// \brief Get the type of the TableComponent.
    /// \return Returns the type of the table.
    std::string getType();


    /// \brief Attach observer to the observer list.
    /// \param observer This is the observer that will be attached to the observer list.
    virtual void attachObserver(Observer *observer) = 0;
    /// \brief This will detach an observer from the observer list.
    /// \param observer This is the observer that will be detached.
    virtual void detachObserver(Observer *observer) = 0;
    /// \brief Notifies an observer.
    virtual void request() = 0;

};

#endif