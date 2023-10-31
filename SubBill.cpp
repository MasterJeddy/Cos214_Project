//===-- COS214_Project/SubBill.cpp - SubBill class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the SubBill.h file.
/// 
///
//===----------------------------------------------------------------------===//

#include "SubBill.h"

SubBill::SubBill(std::string itemName, double itemCost){
    this->name = itemName;
    this->total = itemCost;
}

double SubBill::getTotal(){
    return total;
}

std::string SubBill::getName(){
    return name;
}

// SubBill::~SubBill(){

// }

void SubBill::add(BillComponent* component){

}

void SubBill::remove(BillComponent* component){

}