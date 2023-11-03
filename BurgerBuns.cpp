//
// Created by Kymberley Strydom on 02/11/2023.
//

#include "BurgerBuns.h"

void BurgerBuns::add(Burger *) {
    //do nothing
}

double BurgerBuns::totalPrice() {
    return getPrice();
}

BurgerBuns::BurgerBuns(): Burger() {
    setPrice(5.0);
}

BurgerBuns::~BurgerBuns() = default;
