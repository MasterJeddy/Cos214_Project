//
// Created by maili on 2023/11/03.
//

#ifndef COS214_PROJECT__IOINTERFACETUI_H
#define COS214_PROJECT__IOINTERFACETUI_H
#include "IOInterface.h"

class IOInterfaceTUI:public IOInterface{
private:
  /// \brief Renders other objects in text format
  void render();
  /// \brief Ask UserInput and returns command to be executed
  /// \return Command to be executed
  UserCommand* queryUser();
public:
  /// \brief Overides poll and uses cout and cin statements to interact with user
  void poll() override;
};

#endif //COS214_PROJECT__IOINTERFACETUI_H
