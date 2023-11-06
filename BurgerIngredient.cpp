//
// Created by Geordan Strydom on 03/11/2023.
//

#include "BurgerIngredient.h"

BurgerIngredient::BurgerIngredient(): Burger() {
    ingrediant = nullptr;
}

double BurgerIngredient::totalPrice() {
    double price = getPrice();
    if(ingrediant != nullptr)
    {
        price += ingrediant->totalPrice();
    }
    return price;
}

void BurgerIngredient::add(Burger * newIng) {
  if (ingrediant == nullptr)
    ingrediant = newIng;
  else
    ingrediant->add(newIng);
}

BurgerIngredient::~BurgerIngredient() = default;
