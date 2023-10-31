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
    bool run= true;
    UserCommand* command;
    while (run) {
      command = queryUser();
      if(!command){
        run = false;
      } else  {
        commandLog->addEntry(command);
        command->execute();
      }
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
        default:break;
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
  std::cout << "What do you want to do" << std::endl;
  do {
    std::cin >> c;
    switch (c) {
    case '1': {
      return new Save(commandLog,logs);
    } break;
    case '2': {
      return new Load(commandLog,logs);
    } break;
    case 'q': {
      return nullptr;
    } break;
    default: {
      std::cout << "I don't know how to do that" << std::endl;
    } break;
    }
  } while (true);
}
InputPoll::~InputPoll() {
  delete commandLog;
}
