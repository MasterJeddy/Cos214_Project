//
// Created by nield on 2023/10/30.
//

#include "HeadChef.h"
#include "SauceChef.h"
#include "GarnishChef.h"
#include "ButcherChef.h"
HeadChef::HeadChef() {
  // TODO: BakerChef needs to be instantiated last since it needs its successor
  Chef* lastChef = new SauceChef();
  Chef* thirdChef = new ButcherChef(lastChef);
  Chef* secondChef = new GarnishChef(thirdChef);
  firstChef = new BakerChef(secondChef);
}

bool HeadChef::finishOrder(Order* order) {
  // TODO: check for each topping in order whether
  //  we have the specified amounts in the burger decorator
  return true;
}
Order HeadChef::startOrders() {
  // placeholder temporary implementation
  // firstChef.handleOrder
  return Order("");
}
