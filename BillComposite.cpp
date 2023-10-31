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

BillComposite::BillComposite(std::string compositeName){
    this->name = compositeName;
}

void BillComposite::add(BillComponent* component){
    children.push_back(component);
}

std::string BillComposite::getName(){
    return name;
}

void BillComposite::remove(BillComponent* component){
    
    std::vector<BillComponent*>::iterator miki = children.begin();
    for (miki; miki<children.end();miki++)
    {
        if ((*miki)->getName() == component->getName())
        {
            children.erase(miki);
            break;
        }
        
    }
    
}

// BillComposite::~BillComposite(){
    
// }

