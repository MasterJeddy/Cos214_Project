//
// Created by nield on 2023/11/02.
//

#ifndef COS214_PROJECT__SAUCECHEF_H
#define COS214_PROJECT__SAUCECHEF_H

//===-- COS214_Project/SauceChef.h - SauceChef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SauceChef class,
/// and can be seen as the last handler in the chain of responsibility pattern.
/// \brief This class is responsible for adding any sauces to the burger decorator
/// if any is needed in the order.
///
//===----------------------------------------------------------------------===//

#include "Chef.h"
class SauceChef : public Chef {
public:
  /// \brief Constructor for the SauceChef Class, intended to be the last chef in the chain, so no successor
  SauceChef();
  /// \brief Adds at most one of any of the sauces required by the passed in order
  /// \param order current unfinished order
  /// \return The order after sauces are added
  Order* handleOrder(Order* order) override;
  /// \brief Destructor for the SauceChef class
  ~SauceChef();
};

#endif //COS214_PROJECT__SAUCECHEF_H
