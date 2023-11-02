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
/// \brief Get the next finished order in the finished order queue
/// \return nullptr if no orders are ready to be collected, otherwise returns order*
Order *Kitchen::getFinishedOrder() {
  if (finishedOrders.empty())
    return nullptr;

  Order* out = finishedOrders.front();
  finishedOrders.pop();
  return out;
}
