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
  spriteSheet = new olc::Sprite("./Resources/colored_tilemap_packed.png");
  spriteSheetDecal = new olc::Decal(spriteSheet);
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


  Clear(olc::BLACK);
  //Draw Kitchen
  int ordersInKitchen = Kitchen::getInstance()->headChef.currentOrders.size();
  for (int i =0;i<Kitchen::getInstance()->headChef.maxOrders;i+=3){
      int j = i/3;
      DrawPartialDecal({32,static_cast<float>(32+j*96)},{32,32},spriteSheetDecal,{72,0},{8,8});
      DrawPartialDecal({64,static_cast<float>(32+j*96)},{32,32},spriteSheetDecal,{72,0},{8,8});
      DrawPartialDecal({96,static_cast<float>(32+j*96)},{32,32},spriteSheetDecal,{72,0},{8,8});

      DrawPartialDecal({32,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{56,24},{8,8});
      DrawPartialDecal({64,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{56,24},{8,8});
      DrawPartialDecal({96,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{56,24},{8,8});
      if (ordersInKitchen>0){
        DrawPartialDecal({32,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{40,32},{8,8});
        DrawPartialDecal({64,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{80,64},{8,8});
        DrawPartialDecal({96,static_cast<float>(64+j*96)},{32,32},spriteSheetDecal,{72,64},{8,8});
      }
      ordersInKitchen--;
  }
  //Draw Floor
  int waitingCustomers = Floor::instance()->getWaitingCustomers().size();
  for (int i=0;i<waitingCustomers;i++){
    DrawPartialDecal({500,static_cast<float>(400-i*32)},{32,32},spriteSheetDecal,{120,0},{8,8});
  }

  auto tables = Floor::instance()->getTables();
  olc::vi2d tablePos = {0,0};
  for (auto* table:tables){
    if (table->getTableState()->getName() == "Free"){
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{56,24},{8,8});
    } else if (table->getTableState()->getName() == "Eating"){
      DrawPartialDecal((olc::vf2d){600,32}+tablePos*64,{32,32},spriteSheetDecal,{120,0},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{56,24},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{88,48},{8,8});
    } else if (table->getTableState()->getName() == "WaitingOnFood" ){
      DrawPartialDecal((olc::vf2d){600,32}+tablePos*64,{32,32},spriteSheetDecal,{120,0},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{56,24},{8,8});
    } else if (table->getTableState()->getName() == "Busy" ){
      DrawPartialDecal((olc::vf2d){600,32}+tablePos*64,{32,32},spriteSheetDecal,{120,0},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{56,24},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{8,64},{8,8});
    } else if (table->getTableState()->getName() == "Bill" ){
      DrawPartialDecal((olc::vf2d){600,32}+tablePos*64,{32,32},spriteSheetDecal,{120,0},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{56,24},{8,8});
      DrawPartialDecal((olc::vf2d){600,64}+tablePos*64,{32,32},spriteSheetDecal,{72,56},{8,8});
    }

    tablePos.x++;
    if (tablePos.x%10 ==0){
      tablePos.y++;
      tablePos.x = 0;
    }
  }

  int maitreDCount = Floor::instance()->getMaitreDs().size();
  for (int i=0;i<maitreDCount;i++){
    DrawPartialDecal({300,static_cast<float>(440-i*32)},{32,32},spriteSheetDecal,{88,0},{8,8});

  }

  int waiterCount = Floor::instance()->getWaiterCount();
  for (int i=0;i<waiterCount;i++){
    DrawPartialDecal({260,static_cast<float>(440-i*32)},{32,32},spriteSheetDecal,{64,0},{8,8});

  }
  //Render kitchen debug tab
  DrawStringDecal({50,5},"Kitchen info",olc::WHITE);
  DrawStringDecal({30,15},"Chefs: "+std::to_string(Kitchen::getInstance()->headChef.maxOrders));

  int orderQueueSize = 0;
  Order* order;
  int FinishedOrdersOffset = 0;
  //Render current order queue
  orderQueueSize = Kitchen::getInstance()->headChef.currentOrders.size();
  DrawStringDecal({30,25},"Current Orders:");
  ;
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.currentOrders.front();
    Kitchen::getInstance()->headChef.currentOrders.pop();
    DrawStringDecal({30,static_cast<float>(25+10+10*i)},std::to_string(order->orderNumber)+" "+order->tableID);
    Kitchen::getInstance()->headChef.currentOrders.push(order);
  }
  //Render finished orders
  FinishedOrdersOffset = orderQueueSize+1;
  orderQueueSize = Kitchen::getInstance()->headChef.finishedOrders.size();
  DrawStringDecal({30,static_cast<float>(25+10*FinishedOrdersOffset)},"Finished Orders:");
  for (int i=0;i<orderQueueSize;i++){
    order = Kitchen::getInstance()->headChef.finishedOrders.front();
    Kitchen::getInstance()->headChef.finishedOrders.pop();
    DrawStringDecal({30,static_cast<float>(25+10+10*FinishedOrdersOffset+10*i)},std::to_string(order->orderNumber)+" "+order->tableID);
    Kitchen::getInstance()->headChef.finishedOrders.push(order);
  }
   //Render Floor debug tab
  DrawStringDecal({300,5},"Floor info",olc::WHITE);
  //Render Waiters
  DrawStringDecal({225,15},"Waiters:",olc::WHITE);
  auto waiters = Floor::instance()->getWaiters();
  int offset =0;
  for (auto* waiter:waiters ){
    offset++;
    DrawStringDecal({225,static_cast<float>(15+10*offset)},waiter->id);
    int xoffset = 0;
    for (const auto& table:waiter->assignedTableIds){
      xoffset++;
      DrawStringDecal({static_cast<float>(225+35*xoffset),static_cast<float>(15+10*offset)},table);
    }
  }
  // Draw Customers
  offset++;
  DrawStringDecal({225,static_cast<float>(15+10*offset)},"Customers Queue:",olc::WHITE);
  auto customers =Floor::instance()->getWaitingCustomers();
  while (!customers.empty()){
    offset++;
    DrawStringDecal({225,static_cast<float>(15+10*offset)},customers.front()->getId());
    customers.pop();
  }
  //Draw MaitreD
  offset =0;
  DrawStringDecal({400,15},"MaitreD:",olc::WHITE);
  auto maitreDs = Floor::instance()->getMaitreDs();
  for (auto* maitreD:maitreDs){
    offset++;
    DrawStringDecal({400,static_cast<float>(15+10*offset)},maitreD->id);
  }
  //Draw Tables
  offset++;
  DrawStringDecal({400,static_cast<float>(15+10*offset)},"Tables:",olc::WHITE);
  tables = Floor::instance()->getTables();
  for (auto* table:tables){
    offset++;
    drawTableDebug(table,offset,0);
    //DrawStringDecal({400,15+10*offset},table->getId());
  }
  //Draw Log
  DrawStringDecal({750,5},"Log info",olc::WHITE);
  CommandLogIterator *it = commandLog->createIterator();
  offset = 0;
  for (it->first(); !it->isDone(); it->next())
  {
    offset++;
    switch (it->currentItem()->getType())
    {
    case COMMANDS::SAVE:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Save");
      break;
    case COMMANDS::LOAD:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Load");
      break;
    case COMMANDS::TOGGLE_HELP:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Toggle Help");
      break;
    case COMMANDS::TOGGLE_LOG:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Toggle Log");
      break;
    case COMMANDS::HIRE_MAITRE_D:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Hire Maitre D");
      break;
    case COMMANDS::BUY_TABLE:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Buy Table");
      break;
    case COMMANDS::EXPAND_FLOOR:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Expand Floor");
      break;
    case COMMANDS::HIRE_WAITER:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Hire Waiter");
      break;
    case COMMANDS::UPDATE:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Update");
      break;
    case COMMANDS::EXPAND_KITCHEN:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Expand Kitchen");
      break;
    case COMMANDS::HIRE_CHEF:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Hire Chef");
      break;
    case COMMANDS::BUY_STOCK:
      DrawStringDecal({720,static_cast<float>(5+10*offset)},"Buy Stock");
      break;
    }
  }

  //DrawClock
  offset = 0;
  DrawStringDecal({950,static_cast<float>(5+10*offset)},"Clock");
  for (auto& time: Clock::instance().timers) {
    offset++;
    DrawStringDecal({930,static_cast<float>(5+10*offset)},time.first+" "+std::to_string(time.second));
  }

  //Draw Controls
  DrawStringDecal({5,705},"U-Update H-Hire Chef W-Hire Waiter M-Hire Waiter B-Buy Table S-Save L-Load Q-Quit");



  return true;
}
void IOInterfaceGUI::drawTableDebug(TableComposite *table,int offset,int xoffset) {
    DrawStringDecal({static_cast<float>(400+155*xoffset),static_cast<float>(15+10*offset)},table->getId()+" "+table->getTableState()->getName());
    for (auto t:table->children){
      xoffset++;
      drawTableDebug((TableComposite*)t,offset,xoffset);
    }
}
bool IOInterfaceGUI::OnUserDestroy() {
  delete spriteSheet;
  delete spriteSheetDecal;

  return true;
}
