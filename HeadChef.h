//
// Created by nield on 2023/10/30.
//

#ifndef COS214_PROJECT__HEADCHEF_H
#define COS214_PROJECT__HEADCHEF_H

//===-- COS214_Project/HeadChef.h - HeadChef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the HeadChef class,
/// and can be seen as the client in the chain of responsibility pattern.
/// \brief Class containing a pointer to the first chef, and is responsible
/// for creating the blank burger object and checking whether the orders are completed.
///
//===----------------------------------------------------------------------===//


#include "Chef.h"
class HeadChef {
private:
//   BakerChef firstChef; // TODO: will be uncommented when implemented

  /// \brief Performs the final checks to verify whether an order is completed;
  /// will be run by startOrder(), and will determine whether the order should
  /// go back through the chef chain during the next tick
  /// \return True if the order matches its corresponding burger objects
  bool finishOrder();

public:
  /// \brief Starts the chain of responsibility of chefs
  /// \param currentOrder : new order from the Kitchen's order queue
  /// \return a completed order with corresponding burger object
  Order startOrder(Order currentOrder);
};

#endif //COS214_PROJECT__HEADCHEF_H
