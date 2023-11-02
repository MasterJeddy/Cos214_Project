//
// Created by nield on 2023/10/30.
//

#include "HeadChef.h"
#include "SauceChef.h"
#include "GarnishChef.h"
#include "ButcherChef.h"
HeadChef::HeadChef() {
  Chef* lastChef = new SauceChef();
  Chef* thirdChef = new ButcherChef(lastChef);
  Chef* secondChef = new GarnishChef(thirdChef);
  firstChef = new BakerChef(secondChef);
}

bool HeadChef::finishOrder(Order* order) {
  // TODO: check for each topping in order whether
  //  we have the specified amounts in the burger decorator

  int sum = order->beefPatty + order->chickenPatty + order->veganPatty
      + order->wantsKetchup + order->wantsMustard + order->wantsMayo;
  sum += order->wantsLettuce + order->wantsPickles + order->wantsTomato;

  if (sum == 0)
    order->complete = true;


  // if the order is not finished maybe it should be added to the
  // current order queue or finished order queue depending on order->complete
  return order->complete;
}
Order* HeadChef::startOrders() {
  // placeholder temporary implementation
  // firstChef.handleOrder
// add the finished orders
  return new Order("");
}
Order *HeadChef::getFinishedOrder() {
  if (finishedOrders.empty())
    return nullptr;

  Order* out = finishedOrders.front();
  finishedOrders.pop();
  return out;
}
