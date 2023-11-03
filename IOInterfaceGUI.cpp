//
// Created by maili on 2023/11/03.
//

#include "IOInterfaceGUI.h"
void IOInterfaceGUI::poll() {
  if (this->Construct(640,360,1,1))
      this->Start();
}

bool IOInterfaceGUI::OnUserCreate() {
  return true;
}

bool IOInterfaceGUI::OnUserUpdate(float fElapsedTime) {
  for (int x = 0; x < ScreenWidth(); x++)
    for (int y = 0; y < ScreenHeight(); y++)
      Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
  return true;
}
