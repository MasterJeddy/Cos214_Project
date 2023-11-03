//
// Created by nield on 2023/11/02.
//

#ifndef COS214_PROJECT__GARNISHCHEF_H
#define COS214_PROJECT__GARNISHCHEF_H

//===-- COS214_Project/GarnishChef.h - GarnishChef class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the GarnishChef class,
/// and can be seen as the second handler in the chain of responsibility pattern.
/// \brief This class is responsible for adding any garnish to the burger decorator
/// if any is needed in the order.
///
//===----------------------------------------------------------------------===//

#include "Chef.h"
class GarnishChef: public Chef {
public:
  GarnishChef(Chef* _successor);
  Order* handleOrder(Order* order) override;
  ~GarnishChef();
};

#endif //COS214_PROJECT__GARNISHCHEF_H
