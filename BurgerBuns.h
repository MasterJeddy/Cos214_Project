//===-- COS214_Project/BurgerBuns.h - BurgerBuns class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of an BurgerBuns class. The BurgerBuns is a
/// Concrete component in the decorator pattern that will be used to be the unit of
/// the burger that ingredients are added to.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BURGERBUNS_H
#define COS214_PROJECT_BURGERBUNS_H

#include "Burger.h"
class BurgerBuns: public Burger {
    public:
        BurgerBuns();
        void add(Burger *) override;
        double totalPrice() override;
        ~BurgerBuns();
};


#endif //COS214_PROJECT_BURGERBUNS_H
