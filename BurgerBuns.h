//
// Created by Kymberley Strydom on 02/11/2023.
//

#ifndef COS214_PROJECT_BURGERBUNS_H
#define COS214_PROJECT_BURGERBUNS_H

#include "Burger.h"
class BurgerBuns: public Burger {
    public:
        BurgerBuns();
        void add(Burger *) override;
        double totalPrice() override;
        ~BurgerBuns();
};


#endif //COS214_PROJECT_BURGERBUNS_H
