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
/// \brief Class containing a pointer to the first chef, and is responsible
/// for adding bread to the burger decorator if any is needed in the order.
///
//===----------------------------------------------------------------------===//

#include "Chef.h"
class BakerChef : public Chef{
public:
  BakerChef(Chef* _successor);
  Order* handleOrder(Order* order) override;
  ~BakerChef();
};

#endif //COS214_PROJECT__BAKERCHEF_H
