//===-- COS214_Project/Logs.cpp - Logs class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the Logs class. Logs serves as a
/// caretaker in the memento design pattern. It is used to store temporary
/// SavedLogs and to save and load SavedLogs to disk.
///
//===----------------------------------------------------------------------===//

#include "Logs.h"
#include "Save.h"
#include "Load.h"
#include <fstream>

void Logs::dumpToFile(std::string& file) {
  std::ofstream MyFile(file+".dat",std::ios::out);
  if (temp == nullptr)
    return;
  auto* commands = temp->getCommands();
  for (auto com:*commands){
    MyFile << (int)com->getType() << std::endl;
  }
  MyFile.close();
}

SavedLog * Logs::loadFromFile(std::string& file) {

  if (temp == nullptr) {

  }

  auto* commands = temp->getCommands();
  while (!commands->empty()){
    delete commands->back();
    commands->pop_back();
  }

  std::ifstream MyReadFile(file+".dat");
  std::string temps;
  while (getline(MyReadFile, temps)) {
    switch ((COMMANDS)std::stoi(temps)) {
    case COMMANDS::SAVE:
      commands->push_back(new Save(nullptr, nullptr));
      break;
    case COMMANDS::LOAD:
      commands->push_back(new Load(nullptr, nullptr));
      break;
    case COMMANDS::HIRE_MAITRE_D:
      commands->push_back(new HireMaitreD(nullptr));
      break;
    case COMMANDS::BUY_TABLE:
      commands->push_back(new BuyTable(nullptr));
      break;
    case COMMANDS::EXPAND_FLOOR:
      commands->push_back(new ExpandFloor(nullptr));
      break;
    case COMMANDS::HIRE_WAITER:
      commands->push_back(new HireWaiter(nullptr));
      break;
    case COMMANDS::UPDATE:
      commands->push_back(new Update(nullptr, nullptr));
      break;
    case COMMANDS::EXPAND_KITCHEN:
      commands->push_back(new ExpandKitchen(nullptr));
      break;
    case COMMANDS::HIRE_CHEF:
      commands->push_back(new HireChef(nullptr));
      break;
    case COMMANDS::BUY_STOCK:
      commands->push_back(new BuyStock(nullptr));
      break;
    }
  }
  MyReadFile.close();

  return temp;
}

void Logs::tempSave(SavedLog* save) {
    delete temp; //Test this nullptr thing
    temp = save;
}

SavedLog * Logs::loadTemp() {
    return temp;
}

Logs::Logs() {
    temp = nullptr;
    saves = new std::map<std::string,SavedLog>();
}

Logs::~Logs() {
  delete temp; //Works cause nullptr
  delete saves;
}
