//===-- COS214_Project/Patty.h - Patty class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the patty class. The patty is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of and is specialized using a strategy pattern
/// for specific types of patties.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_PATTY_H
#define COS214_PROJECT_PATTY_H
#include "BurgerIngredient.h"

class Patty: public BurgerIngredient{
public:
  /// \brief The default constructor for the Patty class
    Patty();
    //prepare

protected:
  /// \brief the destructor for the Patty class, only to be called by subclasses
    virtual ~Patty() override;
};


#endif //COS214_PROJECT_PATTY_H
