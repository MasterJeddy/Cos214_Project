//===-- COS214_Project/InputPoll.cpp - InputPoll class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the InputPoll class. InputPoll will
/// serve as an invoker in the command and the main class through which user
/// can interact with the system. The entire system will be driven forward
/// by the commands emitted by this class.
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include "InputPoll.h"
#include "Save.h"
#include "Load.h"

void InputPoll::poll() {
    //std::cout << "What do you want to do" << std::endl;
    render();
    bool run= true;
    UserCommand* command;
    while (run) {
      command = queryUser();
      if(!command){
        run = false;
      } else  {
        commandLog->addEntry(command);
        command->execute();
        delete command;
      }
      render();
    }
}



void InputPoll::resetToLog(CommandLog* log) {
  CommandLogIterator* it = log->createIterator();
  for (it->first();!it->isDone();it->next()){
    if (it->currentItem()->getType() != COMMANDS::LOAD && it->currentItem()->getType() != COMMANDS::SAVE){
        //Update paramaters as needed
        switch (it->currentItem()->getType()) {
        case COMMANDS::HIRE_MAITRE_D:break;
        case COMMANDS::BUY_TABLE:break;
        case COMMANDS::EXPAND_FLOOR:break;
        case COMMANDS::HIRE_WAITER:break;
        case COMMANDS::UPDATE:break;
        case COMMANDS::EXPAND_KITCHEN:break;
        case COMMANDS::HIRE_CHEF:break;
        case COMMANDS::BUY_STOCK:break;
        case COMMANDS::TOGGLE_HELP:
          ((ToggleHelp*)it->currentItem())->setInputPoll(this);
          break;
        case COMMANDS::TOGGLE_LOG:
          ((ToggleLog*)it->currentItem())->setInputPoll(this);
          break;
        default: break;
        }
        it->currentItem()->execute();
    }
  }
  delete it;

}

InputPoll::InputPoll() {
  commandLog = new CommandLog(this);
  logs = new Logs;
}

UserCommand* InputPoll::queryUser() {
  char c;
  do {
    std::cin >> c;
    switch (c) {
    case '1': {
      return new Save(commandLog,logs);
    } break;
    case '2': {
      return new Load(commandLog,logs);
    } break;
    case '3': {
      std::string file;
      std::cin >> file;
      return new Save(commandLog,logs,&file);
    } break;
    case '4': {
      std::string file;
      std::cin >> file;
      return new Load(commandLog,logs,&file);
    } break;
    case '5': {
      return new Update();
    } break;
    case '6': {
      return new ToggleLog(this);
    } break;
    case '7': {
      return new ToggleHelp(this);
    } break;
    case 'q': {
      return nullptr;
    } break;
    default: {
    } break;
    }
  } while (true);
}

InputPoll::~InputPoll() {
  delete logs;
  delete commandLog;
}

void InputPoll::render() {
      if (!checkFlag(DONT_DRAW_HELP)){
          std::cout << "What do you want to do?" << std::endl;
          std::cout << "1. Save to memory" << std::endl;
          std::cout << "2. Load from memory" << std::endl;
          std::cout << "3. Save to file" << std::endl;
          std::cout << "4. Load from file" << std::endl;
          std::cout << "5. Update" << std::endl;
          std::cout << "6. Toggle Log View" << std::endl;
          std::cout << "7. Toggle Help View" << std::endl;
      }

      if  (checkFlag(DRAW_LOG)){
        CommandLogIterator* it = commandLog->createIterator();
        for (it->first();!it->isDone();it->next()){
          switch(it->currentItem()->getType()){
          case COMMANDS::SAVE:
            std::cout<< "Save" << std::endl;
            break;
          case COMMANDS::LOAD:
            std::cout<< "Load" << std::endl;
            break;
          case COMMANDS::TOGGLE_HELP:
            std::cout<< "Toggle Help" << std::endl;
          break;
          case COMMANDS::TOGGLE_LOG:
            std::cout<< "Toggle Log" << std::endl;
            break;
          case COMMANDS::HIRE_MAITRE_D:
            std::cout<< "Hire Maitre D" << std::endl;
            break;
          case COMMANDS::BUY_TABLE:
            std::cout<< "Buy Table" << std::endl;
            break;
          case COMMANDS::EXPAND_FLOOR:
            std::cout<< "Expand Floor" << std::endl;
            break;
          case COMMANDS::HIRE_WAITER:
            std::cout<< "Hire Waiter" << std::endl;
            break;
          case COMMANDS::UPDATE:
            std::cout<< "Update" << std::endl;
            break;
          case COMMANDS::EXPAND_KITCHEN:
            std::cout<< "Expand Kitchen" << std::endl;
            break;
          case COMMANDS::HIRE_CHEF:
            std::cout<< "Hire Chef" << std::endl;
            break;
          case COMMANDS::BUY_STOCK:
            std::cout<< "Buy Stock" << std::endl;
            break;
          }
        }
        delete it;
      }
}
void InputPoll::addFlag(DRAW_FLAGS flag) {
  drawState = drawState|flag;
}

void InputPoll::removeFlag(DRAW_FLAGS flag) {
  drawState = drawState^flag;
}

bool InputPoll::checkFlag(DRAW_FLAGS flag) const {
  return drawState&flag;
}
