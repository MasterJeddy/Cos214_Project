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
  /// \brief The constructor for the BurgerIngredient class
        BurgerIngredient();
  /// \brief Calculates the total price of all connected burger ingredients in the decorator list
  /// \return the total price of the burger
        double totalPrice() override;
        /// \brief adds a burger to the end of the decorator chain
        void add(Burger*) override;
    protected:
  /// \brief The destructor for the BurgerIngredient class
        ~BurgerIngredient() override;
};


#endif //COS214_PROJECT_BURGERINGREDIENT_H
