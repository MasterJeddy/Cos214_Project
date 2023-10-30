//
// Created by nield on 2023/10/30.
//

#include "Chef.h"

Chef::Chef(Chef *_successor) {
  successor = _successor;
}
Chef::~Chef() {
  delete successor;
}
