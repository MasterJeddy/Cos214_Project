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

class Burger
{
private:
    double price;

public:
    Burger();
    virtual void add(Burger *) = 0;
    virtual double totalPrice() = 0;
    double getPrice() const;
    void setPrice(double);
    virtual ~Burger();
};

#endif // PROJECT__BURGER_H