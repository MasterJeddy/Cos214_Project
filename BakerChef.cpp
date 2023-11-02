//
// Created by nield on 2023/11/02.
//

#include "BakerChef.h"
BakerChef::BakerChef(Chef *_successor) : Chef(_successor) {}
Order* BakerChef::handleOrder(Order *order) {

  return order;
}

// no need to call base class destructor
BakerChef::~BakerChef()= default;
