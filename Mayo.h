//===-- COS214_Project/Mayo.h - Mayo class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Mayo class. The mayo is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_MAYO_H
#define COS214_PROJECT_MAYO_H
#include "BurgerIngredient.h"

class Mayo :public BurgerIngredient{
public:
    Mayo();
    ~Mayo() override;
};


#endif //COS214_PROJECT_MAYO_H
