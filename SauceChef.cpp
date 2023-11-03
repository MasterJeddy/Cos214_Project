//
// Created by nield on 2023/11/02.
//

#include "SauceChef.h"
SauceChef::SauceChef() {}

Order *SauceChef::handleOrder(Order *order) {
  // TODO: logic to add to the burger decorator

  if (order->wantsKetchup > 0) {
    // here
    order->wantsKetchup--;
  }
  if (order->wantsMustard > 0) {
    // here
    order->wantsMustard--;
  }
  if (order->wantsMayo > 0) {
    // and here
    order->wantsMayo--;
  }

  return order;
}

SauceChef::~SauceChef() {
  delete successor;
}
