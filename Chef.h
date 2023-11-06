//
// Created by nield on 2023/10/30.
//

#ifndef COS214_PROJECT__CHEF_H
#define COS214_PROJECT__CHEF_H

//===-- COS214_Project/Chef.h - Chef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the HeadChef class,
/// and can be seen as the handler in the chain of responsibility pattern.
/// \brief Class which all other chef types will inherit from.
///
//===----------------------------------------------------------------------===//

#include "Order.h"
class Chef {
private:
protected:
  Chef* successor;
/// \brief Constructor that initialises the successor property
/// \param _successor The next chef in the chain to handle the orders after the current chef
  Chef(Chef* _successor);
  /// \brief Default constructor, doesn't initialise the successor
  Chef();
public:
  /// \brief Handles the order in the chef's unique way and passes it to the successor
  /// \param order An unfinished order object
  /// \return the passed in order object after being handled by the chain of chefs once
  virtual Order* handleOrder(Order* order) = 0;
  /// \brief Destructor for the chef class, calls delete on the successor object
  virtual ~Chef();
};

#endif //COS214_PROJECT__CHEF_H
