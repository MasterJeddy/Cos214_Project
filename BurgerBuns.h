//===-- COS214_Project/BurgerBuns.h - BurgerBuns class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of an BurgerBuns class. The BurgerBuns is a
/// Concrete component in the decorator pattern that will be used to be the unit of
/// the burger that ingredients are added to.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BURGERBUNS_H
#define COS214_PROJECT_BURGERBUNS_H

#include "Burger.h"
class BurgerBuns: public Burger {
    public:
  /// \brief Constructor for the BurgerBuns Class
        BurgerBuns();
  /// \brief Adds an ingredient to the tail of the decorator list
        void add(Burger *) override;
        /// \brief calculates the total price of all connected ingredients
        /// \return the total price of the burger
        double totalPrice() override;
        /// \brief the Destructor for the BurgerBuns class
        ~BurgerBuns();
};


#endif //COS214_PROJECT_BURGERBUNS_H
