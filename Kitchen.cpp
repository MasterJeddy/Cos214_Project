//
// Created by nield on 2023/10/26.
//

#include "Kitchen.h"
#include "Clock.h"
Kitchen::Kitchen() {
}

bool Kitchen::addOrder(Order* order) {
  headChef.addOrder(order);
  // if this at some point becomes a point of failure, a fail condition can be added to return false
  return true;
}

void Kitchen::produceBurgers() {
  // TODO: this is where the clock will be used to start producing
  if (Clock::instance().getTime("produceBurger") == 0) {
    headChef.startOrders();
  }

  if (Clock::instance().getTime("produceBurger")  > 3) {
    Clock::instance().removeTime("produceBurger");
  }

  //finishedOrders.push(headChef.startOrder(order));
}
Kitchen *Kitchen::getInstance() {
  if (instance == nullptr)
    instance = new Kitchen();

  return instance;
}
/// \brief Get the next finished order in the finished order queue
/// \return nullptr if no orders are ready to be collected, otherwise returns order*
Order *Kitchen::getFinishedOrder() {

  return headChef.getFinishedOrder();
}
Kitchen::~Kitchen() = default;
Kitchen::Kitchen(Kitchen &) = default;
Kitchen &Kitchen::operator=(Kitchen &) = default;
