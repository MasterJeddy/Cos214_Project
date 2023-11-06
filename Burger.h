//
// Created by nield on 2023/10/26.
//

#ifndef PROJECT__BURGER_H
#define PROJECT__BURGER_H

//===-- COS214_Project/Burger.h - Burger class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Burger class,
/// and is part of the Decorator pattern as the Component interface.
/// \brief Provides the interface that will be mainly used by the chefs
/// to construct the burgers in linked list fashion.
///
//===----------------------------------------------------------------------===//

class Burger {
private:
  double price;
public:
  Burger();
  /// \brief Adds an ingredient to the burger decorator
  virtual void add(Burger*) = 0;
  /// \brief Calculates the total price of the entire decorated burger
  /// \return the total price of the burger
  virtual double totalPrice() = 0;
  /// \brief Refers instead to the price property of the ingredient
  /// \return the price for this particular ingredient
  double getPrice() const;
  /// \brief Changes the price of the ingredient
  void setPrice(double);
  /// \brief Destructor for the burger class
  virtual ~Burger();
};

#endif //PROJECT__BURGER_H
