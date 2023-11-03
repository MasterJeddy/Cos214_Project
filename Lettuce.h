//===-- COS214_Project/Lettuce.h - Lettuce class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Lettuce class. The lettuce is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_LETTUCE_H
#define COS214_PROJECT_LETTUCE_H
#include "BurgerIngredient.h"

class Lettuce:public BurgerIngredient {
public:
    Lettuce();
    ~Lettuce() override;
};


#endif //COS214_PROJECT_LETTUCE_H
