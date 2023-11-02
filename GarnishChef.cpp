//
// Created by nield on 2023/11/02.
//

#include "GarnishChef.h"

GarnishChef::GarnishChef(Chef *_successor) : Chef(_successor) {

}
Order *GarnishChef::handleOrder(Order *order) {
  return order;
}
GarnishChef::~GarnishChef() {
  delete successor;
}
