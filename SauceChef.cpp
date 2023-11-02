//
// Created by nield on 2023/11/02.
//

#include "SauceChef.h"
SauceChef::SauceChef() {}

Order *SauceChef::handleOrder(Order *order) {
  return order;
}

SauceChef::~SauceChef() {
  delete successor;
}
