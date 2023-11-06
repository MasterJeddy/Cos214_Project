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
  /// \brief Creates a chef responsible for adding garnish to burgers
  /// \param _successor the next chef in the chain, will be passed the burger object when this one is done
  GarnishChef(Chef* _successor);
  /// \brief Next step in the chef chain, adds garnish
  /// \param order An unfinished order object
  /// \return The passed in order object with at most one of each garnish object added to the burger
  Order* handleOrder(Order* order) override;
  /// \brief Destructor for the Garnish chef object, deletes successor
  ~GarnishChef();
};

#endif //COS214_PROJECT__GARNISHCHEF_H
