//===-- COS214_Project/BillComponent.h - BillComponent class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BillComponent class which acts here as the
/// the Component participant in the Composite design pattern. This was done so that
/// a bill object could be split up into sub-bills if the table wanted to do so.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BILLCOMPONENT_H
#define COS214_PROJECT_BILLCOMPONENT_H
#include <iostream>
// using namespace std;
class BillComponent
{

public:
    virtual void add(BillComponent *component) = 0;
    virtual void remove(BillComponent *component) = 0;
    virtual double getTotal() = 0;
    virtual ~BillComponent();
    virtual std::string getName() = 0;
};

#endif