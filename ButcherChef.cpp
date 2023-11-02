//
// Created by nield on 2023/11/02.
//

#include "ButcherChef.h"
ButcherChef::ButcherChef(Chef *_successor) : Chef(_successor) {

}
Order *ButcherChef::handleOrder(Order *order) {
  return order;
}
ButcherChef::~ButcherChef() {
  delete successor;
}
