//===-- COS214_Project/Observer.h - Observer class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Observer class which acts here as an Observer participant of
/// the Observer design pattern. It defines the interface of objects that will observe objects implementing
/// the Subject interface.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_OBSERVER_H
#define COS214_PROJECT_OBSERVER_H

#include <string>
#include <sstream>

class TableComposite;
class Customer;

class Observer
{
protected:
    std::string id;
    std::string type;
    std::string state; // can either be FREE or BUSY

public:
    /// @brief This is the constructor for the observer class
    Observer();
    /// @brief This is the destructor for the observer class
    virtual ~Observer();
    /// @brief called when a customer requests a seat
    /// @param customer the customer requesting a seat
    virtual void notify(Customer *customer) = 0;
    /// @brief called when a table requests the waiter's assistance
    /// @param table the table that is currently requesting assistance
    virtual void notify(TableComposite *table) = 0;

    // getters
    
    /// @brief Gets Id of the observer.
    /// @return Returns id as a string.
    virtual std::string getId();
    /// @brief Returns the type of the observer.
    /// @return Returns type of observer as a string.
    virtual std::string getType();
    /// @brief Returns the state 
    /// @return Returns the state as a string.
    virtual std::string getState();
};

#endif