//===-- COS214_Project/BurgerBuns.h - BurgerBuns class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Ketchup class. The ketchup is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_KETCHUP_H
#define COS214_PROJECT_KETCHUP_H
#include "BurgerIngredient.h"

class Ketchup:public BurgerIngredient {
public:
    Ketchup();
    ~Ketchup();
};


#endif //COS214_PROJECT_KETCHUP_H
