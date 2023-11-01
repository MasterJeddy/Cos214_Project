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

class Observer
{
protected:
    std::string id;
    std::string type;
    std::string state; // can either be FREE or BUSY

public:
    Observer();
    virtual ~Observer();
    virtual void notify(Customer *customer) = 0;

    // getters
    virtual std::string getId();
    virtual std::string getType();
    virtual std::string getState();
};

#endif