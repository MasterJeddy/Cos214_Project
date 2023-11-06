//
// Created by maili on 2023/11/03.
//

#ifndef COS214_PROJECT__KITCHENCONTROLLER_H
#define COS214_PROJECT__KITCHENCONTROLLER_H

class KitchenController {
public:
  /// \brief hires a chef
  void hireChef();
  /// \brief updates kitchen subsystem
  void update();
  /// \brief expands kitchen
  void expandKitchen();
  /// \brief buys stock
  void buyStock();
  /// \brief rests floor subsystem
  void reset();
};

#endif //COS214_PROJECT__KITCHENCONTROLLER_H
