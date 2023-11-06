//
// Created by nield on 2023/11/02.
//

#include "ButcherChef.h"
#include "BeefPatty.h"
#include "VeganPatty.h"
#include "ChickenPatty.h"
ButcherChef::ButcherChef(Chef *_successor) : Chef(_successor) {

}
Order *ButcherChef::handleOrder(Order *order) {
  if (order->beefPatty > 0) {
    Burger* ingredient = new BeefPatty();
    // ingredient.prepare();
    order->burger->add(ingredient);

    order->beefPatty--;
  }
  if (order->veganPatty > 0) {
    Burger* ingredient = new VeganPatty();
    // ingredient.prepare();
    order->burger->add(ingredient);

    order->veganPatty--;
  }
  if (order->chickenPatty > 0) {
    Burger* ingredient = new ChickenPatty();
    // ingredient.prepare();
    order->burger->add(ingredient);

    order->chickenPatty--;
  }

  return successor->handleOrder(order);
}
ButcherChef::~ButcherChef() {
  delete successor;
}
