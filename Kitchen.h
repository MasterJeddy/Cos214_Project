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
/// This file contains the declaration of the Kitchen class,
/// functioning as a singleton.
/// \brief Class containing the systems of the kitchen and will
/// be in charge of its operations.
///
//===----------------------------------------------------------------------===//

#include "HeadChef.h"
#include "Order.h"
class Kitchen {
private:
  static Kitchen* instance;

  HeadChef headChef;
  bool isBusy = false;

  Kitchen();
  ~Kitchen();
  Kitchen(Kitchen&);
  Kitchen& operator=(Kitchen&);

public:
  static Kitchen* getInstance();
  bool addOrder(Order* order);
  Order* getFinishedOrder();
  void produceBurgers();
  friend class IOInterfaceGUI;
};

#endif //COS214_PROJECT__KITCHEN_H
