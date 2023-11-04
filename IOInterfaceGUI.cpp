//
// Created by maili on 2023/11/03.
//

#include "IOInterfaceGUI.h"
#include "Kitchen.h"


void IOInterfaceGUI::poll() {
  if (this->Construct(640,360,1,1))
      this->Start();
}

bool IOInterfaceGUI::OnUserCreate() {
  Kitchen::getInstance()->addOrder(new Order("table-1"));
  Kitchen::getInstance()->addOrder(new Order("table-1"));
  Kitchen::getInstance()->addOrder(new Order("table-1"));
  Kitchen::getInstance()->addOrder(new Order("table-1"));

  return true;
}

bool IOInterfaceGUI::OnUserUpdate(float fElapsedTime) {




  //Render kitchen info tab
  Clear(olc::BLACK);
  DrawString({50,5},"Kitchen info",olc::WHITE,1);

  //Render current order queue
  int orderQueueSize = Kitchen::getInstance()->headChef.currentOrders.size();
  DrawString({30,15},"Current Orders:");
  Order* order;
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.currentOrders.front();
    Kitchen::getInstance()->headChef.currentOrders.pop();
    DrawString({30,25+10*i},std::to_string(order->orderNumber));
    Kitchen::getInstance()->headChef.currentOrders.push(order);
  }
  //Render finishe orders


  //




  return true;
}
