//
// Created by nield on 2023/11/02.
//

#include "BakerChef.h"
#include "BurgerBuns.h"
BakerChef::BakerChef(Chef *_successor) : Chef(_successor) {}
Order* BakerChef::handleOrder(Order *order) {

  if (order->burger == nullptr) {
    order->burger = new BurgerBuns();
  }
  return successor->handleOrder(order);
}

// no need to call base class destructor
BakerChef::~BakerChef() {
  delete successor;
}
