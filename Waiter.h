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

class Waiter : public Observer
{
private:
    // std::queue<>

public:
    Waiter();
    virtual void update();
};

#endif