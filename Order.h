//
// Created by nield on 2023/10/26.
//

#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H

//===-- COS214_Project/Order.h - Order struct definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Order struct,
/// and is to be used across the project.
/// \brief Provides a struct used to contain customer orders, created by
/// waiters and later passed down to the chefs. All values are 0 by default
/// so that only values that are stated by the customer need be modified.
///
//===----------------------------------------------------------------------===//


struct Order {
public:
  /// \brief Default constructor, all values default to 0 and assigns orderNumber (starts counting orders at 1)
  Order() {
    orderNumber = ++totalOrders;
  };
  static int totalOrders = 0;
  int orderNumber = 0;
  int wantsKetchup = 0;
  int wantsMustard = 0;
  int wantsMayo = 0;
  int beefPatty = 0;
  int chickenPatty = 0;
  int veganPatty = 0;
  int wantsLettuce = 0;
  int wantsTomato = 0;
  int wantsPickles = 0;
  bool complete = false;
};


#endif //PROJECT_ORDER_H
