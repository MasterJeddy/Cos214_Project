//
// Created by maili on 2023/10/23.
//
#define OLC_PGE_APPLICATION
#define OLC_SOUNDWAVE

#include "IOInterfaceTUI.h"
#include "IOInterfaceGUI.h"

int randomvalue(){
  return 3;
}

int main() {
  auto* io = new IOInterfaceGUI();
  io->poll();
  delete io;
  return 0;
}