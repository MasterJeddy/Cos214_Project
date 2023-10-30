//
// Created by nield on 2023/10/26.
//

#ifndef COS214_PROJECT__KITCHEN_H
#define COS214_PROJECT__KITCHEN_H

//===-- COS214_Project/Kitchen.h - Kitchen class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Kitchen class.
/// \brief Class containing the systems of the kitchen and will
/// be in charge of its operations.
///
//===----------------------------------------------------------------------===//

#include "HeadChef.h"
#include "Order.h"
#include <queue>
class Kitchen {
private:
  HeadChef headChef;
  std::queue<Order> orderQueue;
  std::queue<Order> finishedOrders;
  bool isBusy = false;

public:
  bool addOrder(Order order);
  void produceBurgers();
};

#endif //COS214_PROJECT__KITCHEN_H
