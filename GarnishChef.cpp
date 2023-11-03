//
// Created by nield on 2023/11/02.
//

#include "GarnishChef.h"

GarnishChef::GarnishChef(Chef *_successor) : Chef(_successor) {

}
Order *GarnishChef::handleOrder(Order *order) {
  // TODO: logic to add to the burger decorator

  if (order->wantsLettuce > 0) {
    // here
    order->wantsLettuce--;
  }
  if (order->wantsTomato > 0) {
    // here
    order->wantsTomato--;
  }
  if (order->wantsPickles > 0) {
    // and here
    order->wantsPickles--;
  }

  return successor->handleOrder(order);
}
GarnishChef::~GarnishChef() {
  delete successor;
}
