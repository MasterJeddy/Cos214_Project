//
// Created by maili on 2023/11/03.
//

#include "IOInterfaceGUI.h"
#include "Kitchen.h"
#include "Floor.h"
#include "Save.h"
#include "Load.h"
#include "Clock.h"

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
  if (GetKey(olc::H).bPressed){
    command = new HireChef(kitchenController);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::W).bPressed){
    command = new HireWaiter(floorController);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::M).bPressed){
    command = new HireMaitreD(floorController);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::B).bPressed){
    command = new BuyTable(floorController);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::S).bPressed){
    command = new Save(commandLog,logs);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::L).bPressed){
    command = new Load(commandLog,logs);
    commandLog->addEntry(command);
    command->execute();
    delete command;
  }
  if (GetKey(olc::Q).bPressed){
    return false;
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
    DrawString({30,25+10+10*i},std::to_string(order->orderNumber)+" "+order->tableID);
    Kitchen::getInstance()->headChef.currentOrders.push(order);
  }
  //Render finished orders
  FinishedOrdersOffset = orderQueueSize+1;
  orderQueueSize = Kitchen::getInstance()->headChef.finishedOrders.size();
  DrawString({30,25+10*FinishedOrdersOffset},"Finished Orders:");
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.finishedOrders.front();
    Kitchen::getInstance()->headChef.finishedOrders.pop();
    DrawString({30,25+10+10*FinishedOrdersOffset+10*i},std::to_string(order->orderNumber)+" "+order->tableID);
    Kitchen::getInstance()->headChef.finishedOrders.push(order);
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
      DrawString({225+35*xoffset,15+10*offset},table);
    }
  }
  // Draw Customers
  offset++;
  DrawString({225,15+10*offset},"Customers Queue:",olc::WHITE,1);
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
  //Draw Log
  DrawString({750,5},"Log info",olc::WHITE,1);
  CommandLogIterator *it = commandLog->createIterator();
  offset = 0;
  for (it->first(); !it->isDone(); it->next())
  {
    offset++;
    switch (it->currentItem()->getType())
    {
    case COMMANDS::SAVE:
      DrawString({720,5+10*offset},"Save");
      break;
    case COMMANDS::LOAD:
      DrawString({720,5+10*offset},"Load");
      break;
    case COMMANDS::TOGGLE_HELP:
      DrawString({720,5+10*offset},"Toggle Help");
      break;
    case COMMANDS::TOGGLE_LOG:
      DrawString({720,5+10*offset},"Toggle Log");
      break;
    case COMMANDS::HIRE_MAITRE_D:
      DrawString({720,5+10*offset},"Hire Maitre D");
      break;
    case COMMANDS::BUY_TABLE:
      DrawString({720,5+10*offset},"Buy Table");
      break;
    case COMMANDS::EXPAND_FLOOR:
      DrawString({720,5+10*offset},"Expand Floor");
      break;
    case COMMANDS::HIRE_WAITER:
      DrawString({720,5+10*offset},"Hire Waiter");
      break;
    case COMMANDS::UPDATE:
      DrawString({720,5+10*offset},"Update");
      break;
    case COMMANDS::EXPAND_KITCHEN:
      DrawString({720,5+10*offset},"Expand Kitchen");
      break;
    case COMMANDS::HIRE_CHEF:
      DrawString({720,5+10*offset},"Hire Chef");
      break;
    case COMMANDS::BUY_STOCK:
      DrawString({720,5+10*offset},"Buy Stock");
      break;
    }
  }

  //DrawClock
  offset = 0;
  DrawString({950,5+10*offset},"Clock");
  for (auto& time: Clock::instance().timers) {
    offset++;
    DrawString({930,5+10*offset},time.first+" "+std::to_string(time.second));
  }

  //Draw Controls
  DrawString({5,705},"U-Update H-Hire Chef W-Hire Waiter M-Hire Waiter B-Buy Table S-Save L-Load Q-Quit");



  return true;
}
void IOInterfaceGUI::drawTableDebug(TableComposite *table,int offset,int xoffset) {
    DrawString({400+155*xoffset,15+10*offset},table->getId()+" "+table->getTableState()->getName());
    for (auto t:table->children){
      xoffset++;
      drawTableDebug((TableComposite*)t,offset,xoffset);
    }
}
