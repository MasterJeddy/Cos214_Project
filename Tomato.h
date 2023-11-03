//===-- COS214_Project/Tomato.h - Tomato class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Tomato class. The tomato is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_TOMATO_H
#define COS214_PROJECT_TOMATO_H
#include "BurgerIngredient.h"

class Tomato: public BurgerIngredient {
public:
    Tomato();
    ~Tomato();
};


#endif //COS214_PROJECT_TOMATO_H
