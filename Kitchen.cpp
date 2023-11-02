//
// Created by nield on 2023/10/26.
//

#include "Kitchen.h"
Kitchen::Kitchen() {
}

bool Kitchen::addOrder(Order* order) {
  orderQueue.push(order);
  // if this at some point becomes a point of failure, a fail condition can be added to return false
  return true;
}

void Kitchen::produceBurgers() {
  // TODO: will be uncommented when it works
  //finishedOrders.push(headChef.startOrder(orderQueue.pop()));
}
Kitchen *Kitchen::getInstance() {
  if (instance == nullptr)
    instance = new Kitchen();

  return instance;
}
