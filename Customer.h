//===-- COS214_Project/Customer.h - Customer class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Customer class which acts here as the Leaf participant in
/// the Composite design pattern. This class implements the interface provided by the ConsumerParty class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_CUSTOMER_H
#define COS214_PROJECT_CUSTOMER_H

#include "TableComponent.h"
#include "Observer.h"
#include <string>
#include <vector>

#include "Constants.h"

class Customer : public TableComponent
{
private:
    std::vector<Customer *> group; // if not empty then also includes this customer
    bool alone;

public:
    Customer(int id);
    virtual ~Customer();

    /// @brief This function will attach an observer to the observerList.
    /// This observer(specifically a maitreD) will watch this customer
    /// @param observer This is the observer that will watch this table.
    virtual void attachObserver(Observer *observer);

    /// @brief This function will detach an observer from the observerList.
    /// @param observer This is the observer that will be removed from the observerList.
    virtual void detachObserver(Observer *observer);

    /// @brief Notifies a maitreD observer when a customer requests for a seat.
    virtual void request();


    /// @brief gets the group size that this customer is a part of(if any)
    /// @return integer representing the size of the group
    int getGroupSize();

    /// @brief gets the vector of customers that this 
    /// @return return the group of customers that this customer is part of
    std::vector<Customer *> getGroup();
    /// @brief This will return whether a customer is alone or not.
    /// @return This will return a boolean indicating if the customer is alone.
    bool isAlone();
    /// @brief This function will add a friend to the customers group
    /// @param frend this customer will be added to another customers group
    void addToGroup(Customer *frend);
};

#endif