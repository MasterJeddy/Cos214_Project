//===-- COS214_Project/Pickles.h - Pickles class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Pickles class. The pickles is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_PICKLES_H
#define COS214_PROJECT_PICKLES_H
#include "BurgerIngredient.h"

class Pickles: public BurgerIngredient{
public:
  /// \brief Constructor for the pickles class
    Pickles();
  /// \brief Destructor for the pickles class
    ~Pickles() override;
};


#endif //COS214_PROJECT_PICKLES_H
