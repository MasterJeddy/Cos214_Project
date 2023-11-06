//
// Created by nield on 2023/10/26.
//

#include "Burger.h"
void Burger::setPrice(double _price) {
  price = _price;
}
double Burger::getPrice() const {
  return price;
}
Burger::Burger() {
  price = 0;
}
Burger::~Burger() = default;
