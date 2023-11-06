//
// Created by nield on 2023/11/02.
//

#ifndef COS214_PROJECT__BAKERCHEF_H
#define COS214_PROJECT__BAKERCHEF_H

//===-- COS214_Project/BakerChef.h - BakerChef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BakerChef class,
/// and can be seen as the first handler in the chain of responsibility pattern.
/// \brief This class is responsible for adding bread to the burger decorator
/// if any is needed in the order.
///
//===----------------------------------------------------------------------===//

#include "Chef.h"
class BakerChef : public Chef{
public:
  /// \brief Constructor for the BakerChef, initialises the successor
  /// \param _successor the next chef in the chain, will be passed any orders handled
  BakerChef(Chef* _successor);
  /// \brief Creates the burger buns for the burger decorator, if there is none
  /// \param order current unfinished order
  /// \return The order after it is passed through the chef chain once
  Order* handleOrder(Order* order) override;
  /// \brief Destructor for the BakerChef class
  ~BakerChef();
};

#endif //COS214_PROJECT__BAKERCHEF_H
