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
  DrawString({30,15},"Chefs: "+std::to_string(Kitchen::getInstance()->headChef.maxOrders));

  int orderQueueSize = 0;
  Order* order;
  int FinishedOrdersOffset = 0;
  //Render current order queue
  orderQueueSize = Kitchen::getInstance()->headChef.currentOrders.size();
  DrawString({30,25},"Current Orders:");
  ;
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.currentOrders.front();
    Kitchen::getInstance()->headChef.currentOrders.pop();
    DrawString({30,25+10+10*i},std::to_string(order->orderNumber));
    Kitchen::getInstance()->headChef.currentOrders.push(order);
  }
  //Render finished orders
  FinishedOrdersOffset = orderQueueSize+1;
  orderQueueSize = Kitchen::getInstance()->headChef.finishedOrders.size();
  DrawString({30,25+10*FinishedOrdersOffset},"Finished Orders:");
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.finishedOrders.front();
    Kitchen::getInstance()->headChef.finishedOrders.pop();
    DrawString({30,25+10+10*FinishedOrdersOffset+10*i},std::to_string(order->orderNumber));
    Kitchen::getInstance()->headChef.finishedOrders.push(order);
  }

  //




  return true;
}
