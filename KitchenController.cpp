//
// Created by maili on 2023/11/03.
//

#include "KitchenController.h"
#include "Kitchen.h"

void KitchenController::hireChef() {
  Kitchen::getInstance()->purchaseChef();
}
void KitchenController::update() {
    Kitchen::getInstance()->produceBurgers();
}
void KitchenController::expandKitchen() {

}
void KitchenController::buyStock() {

}
