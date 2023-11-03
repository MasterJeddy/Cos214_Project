//
// Created by maili on 2023/10/23.
//
#include "IOInterface.h"

int randomvalue(){
  return 3;
}

int main() {
  auto* io = new IOInterface();
  io->poll();
  delete io;
  return 0;
}