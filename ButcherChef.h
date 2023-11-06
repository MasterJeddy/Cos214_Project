//
// Created by nield on 2023/11/02.
//

#ifndef COS214_PROJECT__BUTCHERCHEF_H
#define COS214_PROJECT__BUTCHERCHEF_H

//===-- COS214_Project/ButcherChef.h - ButcherChef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ButcherChef class,
/// and can be seen as the third handler in the chain of responsibility pattern,
/// as well as the context of the patty strategy pattern.
/// \brief This class is responsible for adding any patties to the burger decorator
/// if any is needed in the order.
///
//===----------------------------------------------------------------------===//

#include "Chef.h"
class ButcherChef : public Chef {
public:
  /// \brief Constructor for the ButcherChef Class, initialises successor
  /// \param _successor the next chef in the chain, will be passed the order after this one
  ButcherChef(Chef* _successor);
  /// \brief Adds at most one of each patty type to the burger decorator and passes it to the next chef
  /// \param order current unfinished order
  /// \return The passed in order object after one cycle through the chain
  Order* handleOrder(Order* order) override;
  /// \brief Destructor for the ButcherChef class, deletes successor
  ~ButcherChef();
};

#endif //COS214_PROJECT__BUTCHERCHEF_H
