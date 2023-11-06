//
// Created by nield on 2023/11/02.
//

#include "GarnishChef.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Pickles.h"

GarnishChef::GarnishChef(Chef *_successor) : Chef(_successor) {

}
Order *GarnishChef::handleOrder(Order *order) {

  if (order->wantsLettuce > 0) {
    Burger* ingredient = new Lettuce();
    order->burger->add(ingredient);
    // remember to keep to the ordering of a linked list^^^^

    order->wantsLettuce--;
  }
  if (order->wantsTomato > 0) {
    Burger* ingredient = new Tomato();
    order->burger->add(ingredient);

    order->wantsTomato--;
  }
  if (order->wantsPickles > 0) {
    Burger* ingredient = new Pickles();
    order->burger->add(ingredient);

    order->wantsPickles--;
  }

  return successor->handleOrder(order);
}
GarnishChef::~GarnishChef() {
  delete successor;
}
