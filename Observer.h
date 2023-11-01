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

class Observer
{
private:
    std::string type;
    int id;

public:
    virtual void update() = 0;
    virtual ~Observer();

    //getters
    std::string getId();
    std::string getType();
};

#endif