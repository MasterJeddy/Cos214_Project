//
// Created by nield on 2023/11/02.
//

#include "ButcherChef.h"
ButcherChef::ButcherChef(Chef *_successor) : Chef(_successor) {

}
Order *ButcherChef::handleOrder(Order *order) {
  // TODO: logic to add to the burger decorator
  if (order->beefPatty > 0) {
    // here
    order->beefPatty--;
  }
  if (order->veganPatty > 0) {
    // here
    order->veganPatty--;
  }
  if (order->chickenPatty > 0) {
    // and here
    order->chickenPatty--;
  }

  return successor->handleOrder(order);
}
ButcherChef::~ButcherChef() {
  delete successor;
}
