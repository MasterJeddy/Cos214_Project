//
// Created by nield on 2023/10/26.
//

#include "Kitchen.h"
bool Kitchen::addOrder(Order order) {
  orderQueue.push(order);
  // if this at some point becomes a point of failure, a fail condition can be added to return false
  return true;
}
void Kitchen::produceBurgers() {
  // TODO: will be uncommented when it works
  //headChef.startOrder()
}
