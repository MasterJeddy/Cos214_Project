//===-- COS214_Project/Mustard.h - Mustard class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Mustard class. The mustard is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_MUSTARD_H
#define COS214_PROJECT_MUSTARD_H
#include "BurgerIngredient.h"

class Mustard:public BurgerIngredient {
public:
  /// \brief The constructor for the Mustard class
    Mustard();
    /// \brief The destructor for the Mustard class
    ~Mustard() override;
};


#endif //COS214_PROJECT_MUSTARD_H
