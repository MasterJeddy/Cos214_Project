//===-- COS214_Project/Patty.h - Patty class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the patty class. The patty is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of and is specialized for specific types of patties.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_PATTY_H
#define COS214_PROJECT_PATTY_H
#include "BurgerIngredient.h"

class Patty: public BurgerIngredient{
public:
    Patty();
    //prepare

protected:
    ~Patty() override;
};


#endif //COS214_PROJECT_PATTY_H
