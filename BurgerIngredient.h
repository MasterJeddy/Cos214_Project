//
// Created by Kymberley Strydom on 03/11/2023.
//

#ifndef COS214_PROJECT_BURGERINGREDIENT_H
#define COS214_PROJECT_BURGERINGREDIENT_H
#include "Burger.h"

class BurgerIngredient: public Burger{
    private:
        Burger* ingrediant;
    public:
        BurgerIngredient();
        double totalPrice() override;
        void add(Burger*) override;
    protected:
        ~BurgerIngredient() override;
};


#endif //COS214_PROJECT_BURGERINGREDIENT_H
