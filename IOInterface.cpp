//===-- COS214_Project/IOInterface.cpp - IOInterface class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the IOInterface class. IOInterface will
/// serve as an invoker in the command and the main class through which user
/// can interact with the system. The entire system will be driven forward
/// by the commands emitted by this class. It will also serve the roll of renderer
/// for the entire system.
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include "IOInterface.h"
#include "Save.h"
#include "Load.h"
#include "Clock.h"



void IOInterface::resetToLog(CommandLog *log)
{
  floorController->reset();
  kitchenController->reset();
  Clock::instance().reset();
  CommandLogIterator *it = log->createIterator();
  for (it->first(); !it->isDone(); it->next())
  {
    if (it->currentItem()->getType() != COMMANDS::LOAD && it->currentItem()->getType() != COMMANDS::SAVE)
    {
      // Update paramaters as needed
      switch (it->currentItem()->getType())
      {
      case COMMANDS::HIRE_MAITRE_D:
        break;
      case COMMANDS::BUY_TABLE:
        break;
      case COMMANDS::EXPAND_FLOOR:
        break;
      case COMMANDS::HIRE_WAITER:
        break;
      case COMMANDS::UPDATE:
        break;
      case COMMANDS::EXPAND_KITCHEN:
        break;
      case COMMANDS::HIRE_CHEF:
        break;
      case COMMANDS::BUY_STOCK:
        break;
      case COMMANDS::TOGGLE_HELP:
        ((ToggleHelp *)it->currentItem())->setIOInterface(this);
        break;
      case COMMANDS::TOGGLE_LOG:
        ((ToggleLog *)it->currentItem())->setIOInterface(this);
        break;
      default:
        break;
      }
      it->currentItem()->execute();
    }

  }
  delete it;
}

IOInterface::IOInterface()
{
  commandLog = new CommandLog(this);
  floorController = new FloorController();
  logs = new Logs;
  kitchenController = new KitchenController();
  UserCommand* command = new Save(commandLog,logs);
  command->execute();
  delete command;
}



IOInterface::~IOInterface()
{
  delete logs;
  delete floorController;
  delete commandLog;
  delete kitchenController;
}

void IOInterface::addFlag(DRAW_FLAGS flag)
{
  drawState = drawState | flag;
}

void IOInterface::removeFlag(DRAW_FLAGS flag)
{
  drawState = drawState ^ flag;
}

bool IOInterface::checkFlag(DRAW_FLAGS flag) const
{
  return drawState & flag;
}
