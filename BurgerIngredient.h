//===-- COS214_Project/BurgerIngredient.h - BurgerIngredient class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of an BurgerIngredient class. The BurgerIngredient is the
/// Decorator in the decorator pattern that will be used to be blueprint for all the ingredients
/// classes that will be wrapped on the burgerbuns object.
///
//===----------------------------------------------------------------------===//


#ifndef COS214_PROJECT_BURGERINGREDIENT_H
#define COS214_PROJECT_BURGERINGREDIENT_H
#include "Burger.h"

class BurgerIngredient: public Burger{
    private:
        Burger* ingrediant;
    public:
        BurgerIngredient();
        double totalPrice() override;
        void add(Burger*) override;
    protected:
        ~BurgerIngredient() override;
};


#endif //COS214_PROJECT_BURGERINGREDIENT_H
