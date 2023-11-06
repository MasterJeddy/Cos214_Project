//
// Created by nield on 2023/11/02.
//

#include "SauceChef.h"
#include "Ketchup.h"
#include "Mustard.h"
#include "Mayo.h"
SauceChef::SauceChef() {}

Order *SauceChef::handleOrder(Order *order) {

  if (order->wantsKetchup > 0) {
    Burger* ingredient = new Ketchup();
    order->burger->add(ingredient);

    order->wantsKetchup--;
  }
  if (order->wantsMustard > 0) {
    Burger* ingredient = new Mustard();
    order->burger->add(ingredient);

    order->wantsMustard--;
  }
  if (order->wantsMayo > 0) {
    Burger* ingredient = new Mayo();
    order->burger->add(ingredient);

    order->wantsMayo--;
  }

  return order;
}

SauceChef::~SauceChef() {
  delete successor;
}
