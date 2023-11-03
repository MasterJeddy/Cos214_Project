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
  // using the order properties, checks for each topping in order whether
  //  we have the specified amounts in the burger decorator

  int sum = order->beefPatty + order->chickenPatty + order->veganPatty
      + order->wantsKetchup + order->wantsMustard + order->wantsMayo;
  sum += order->wantsLettuce + order->wantsPickles + order->wantsTomato;

  // organise orders, if unfinished, add to currentOrders to be sent back
  if (sum == 0){
    order->complete = true;

    finishedOrders.push(order);
  }
  else {
    currentOrders.push(order);
  }

  return order->complete;
}

void HeadChef::startOrders() {
  // placeholder temporary implementation
  // firstChef.handleOrder for current max orders
  // add the finished orders to finishedOrders

  for (int i = 0; i < maxOrders; i++) {
    Order* order = nullptr;
    if (currentOrders.empty()) {
      if (!orderQueue.empty()) {
        order = orderQueue.front();
        orderQueue.pop();
      }
    } else {
      order = currentOrders.front();
      currentOrders.pop();
    }

    if (order != nullptr)
      finishOrder(firstChef->handleOrder(order));
  }
}
Order *HeadChef::getFinishedOrder() {
  if (finishedOrders.empty())
    return nullptr;

  Order* out = finishedOrders.front();
  finishedOrders.pop();
  return out;
}
void HeadChef::addOrder(Order* order) {
  currentOrders.push(order);
}
