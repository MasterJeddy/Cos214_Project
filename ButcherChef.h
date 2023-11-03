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
  ButcherChef(Chef* _successor);
  Order* handleOrder(Order* order) override;
  ~ButcherChef();
};

#endif //COS214_PROJECT__BUTCHERCHEF_H
