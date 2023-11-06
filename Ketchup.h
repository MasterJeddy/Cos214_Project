//===-- COS214_Project/Ketchup.h - Ketchup class definition ------*- C++ -*-===//
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
  /// \brief The Constructor for the Ketchup class
    Ketchup();
  /// \brief The Destructor for the Ketchup class
    ~Ketchup() override;
};


#endif //COS214_PROJECT_KETCHUP_H
