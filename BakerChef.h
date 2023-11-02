//
// Created by nield on 2023/11/02.
//

#ifndef COS214_PROJECT__BAKERCHEF_H
#define COS214_PROJECT__BAKERCHEF_H

#include "Chef.h"
class BakerChef : public Chef{
public:
  BakerChef(Chef* _successor);
  Order* handleOrder(Order* order) override;
  ~BakerChef();
};

#endif //COS214_PROJECT__BAKERCHEF_H
