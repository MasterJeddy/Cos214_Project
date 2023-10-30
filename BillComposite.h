//===-- COS214_Project/BillComposite.h - BillComposite class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BillComposite class which acts here as the
/// the Composite participant in the Composite design pattern. This file implements the
/// BillComponent class.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BILLCOMPOSITE_H
#define COS214_PROJECT_BILLCOMPOSITE_H
#include "BillComponent.h"
#include <vector>
 

class BillComposite: public BillComponent
{
    private:
    std::vector<BillComponent*> children;
    std::string name;

    public:
    void add(BillComponent* component);
    void remove(BillComponent* component);
    virtual double getTotal();
    BillComposite(std::string compositeName);
    virtual std::string getName();
    virtual ~BillComposite();
};

#endif