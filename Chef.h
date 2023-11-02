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
  Chef* successor;
protected:
  Chef(Chef* _successor);
public:
  virtual Order* handleOrder(Order* order) = 0;
  virtual ~Chef();
};

#endif //COS214_PROJECT__CHEF_H
