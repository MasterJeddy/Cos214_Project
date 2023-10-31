//===-- COS214_Project/BillComposite.cpp - BillComposite class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the BillComposite.h file.
///
///
//===----------------------------------------------------------------------===//

#include "BillComposite.h"

BillComposite::BillComposite(std::string compositeName)
{
    this->name = compositeName;
}

void BillComposite::add(BillComponent *component)
{
    children.push_back(component);
}

std::string BillComposite::getName()
{
    return name;
}

void BillComposite::remove(BillComponent *component)
{

    std::vector<BillComponent *>::iterator miki = children.begin();
    for (miki; miki < children.end(); miki++)
    {
        if ((*miki)->getName() == component->getName())
        {
            children.erase(miki);
            break;
        }
    }
}

double BillComposite::getTotal()
{   
    
    //loops through all the children in the composite and then will calculate the getTotal for each of the children
    double total = 0;
    for (BillComponent* child: children)
    {
        total += child->getTotal();
    }
    return total; 
}

BillComposite::~BillComposite()
{
}
