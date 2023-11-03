//
// Created by Kymberley Strydom on 03/11/2023.
//

#include "BurgerIngredient.h"

BurgerIngredient::BurgerIngredient(): Burger() {
    ingrediant = nullptr;
}

double BurgerIngredient::totalPrice() {
    double price = getPrice();
    if(ingrediant != nullptr)
    {
        price += ingrediant->getPrice();
    }
    return price;
}

void BurgerIngredient::add(Burger * newIng) {
    ingrediant = newIng;
}

BurgerIngredient::~BurgerIngredient() = default;
