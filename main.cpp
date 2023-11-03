//
// Created by maili on 2023/10/23.
//

#include "IOInterfaceTUI.h"

int randomvalue(){
  return 3;
}

int main() {
  auto* io = new IOInterfaceTUI();
  io->poll();
  delete io;
  return 0;
}