//
// Created by maili on 2023/11/03.
//

#include "IOInterfaceGUI.h"
#include "Kitchen.h"
#include "Floor.h"


void IOInterfaceGUI::poll() {
  if (this->Construct(1280,720,1,1))
      this->Start();
}

bool IOInterfaceGUI::OnUserCreate() {
//  Kitchen::getInstance()->addOrder(new Order("table-1"));
//  Kitchen::getInstance()->addOrder(new Order("table-1"));
//  Kitchen::getInstance()->addOrder(new Order("table-1"));
//  Kitchen::getInstance()->addOrder(new Order("table-1"));

  return true;
}

bool IOInterfaceGUI::OnUserUpdate(float fElapsedTime) {
  UserCommand* command;

  //input
  if (GetKey(olc::U).bPressed){
    command = new Update(floorController,kitchenController);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }



  //Render kitchen debug tab
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
  FinishedOrdersOffset += orderQueueSize+1;
  DrawString({30,25+10*FinishedOrdersOffset},"Orders:");
  orderQueueSize = Kitchen::getInstance()->headChef.orderQueue.size();
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.orderQueue.front();
    Kitchen::getInstance()->headChef.orderQueue.pop();
    DrawString({30,25+10+10*FinishedOrdersOffset+10*i},std::to_string(order->orderNumber));
    Kitchen::getInstance()->headChef.orderQueue.push(order);
  }
  //Render Floor debug tab
  DrawString({300,5},"Floor info",olc::WHITE,1);
  //Render Waiters
  DrawString({225,15},"Waiters:",olc::WHITE,1);
  auto waiters = Floor::instance()->getWaiters();
  int offset =0;
  for (auto* waiter:waiters ){
    offset++;
    DrawString({225,15+10*offset},waiter->id);
    int xoffset = 0;
    for (const auto& table:waiter->assignedTableIds){
      xoffset++;
      DrawString({225+25*xoffset,15+10*offset},table);
    }
  }
  // Draw Customers
  offset++;
  DrawString({225,15+10*offset},"Customers:",olc::WHITE,1);
  auto customers =Floor::instance()->getWaitingCustomers();
  while (!customers.empty()){
    offset++;
    DrawString({225,15+10*offset},customers.front()->getId());
    customers.pop();
  }
  //Draw MaitreD
  offset =0;
  DrawString({400,15},"MaitreD:",olc::WHITE,1);
  auto maitreDs = Floor::instance()->getMaitreDs();
  for (auto* maitreD:maitreDs){
    offset++;
    DrawString({400,15+10*offset},maitreD->id);
  }
  //Draw Tables
  offset++;
  DrawString({400,15+10*offset},"Tables:",olc::WHITE,1);
  auto tables = Floor::instance()->getTables();
  for (auto* table:tables){
    offset++;
    drawTableDebug(table,offset,0);
    //DrawString({400,15+10*offset},table->getId());
  }

  return true;
}
void IOInterfaceGUI::drawTableDebug(TableComposite *table,int offset,int xoffset) {
    DrawString({400+200*xoffset,15+10*offset},table->getId()+" "+table->getTableState()->getName());
    for (auto t:table->children){
      xoffset++;
      drawTableDebug((TableComposite*)t,offset,xoffset);
    }
}
