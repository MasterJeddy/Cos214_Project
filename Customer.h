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
#include <string>

class Customer : public TableComponent
{
private:
    std::string name;
    std::vector<Customer *> group; // also includes this customer

public:
    Customer(int id, std::string name);
    Customer(int id, std::string name, std::vector<Customer *> friends);
    ~Customer();

    virtual void attachObserver(Observer *observer);
    virtual void detachObserver(Observer *observer);
    virtual void request();

    // getters
    int group
};

#endif