//===-- COS214_Project/Load.cpp - Load class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the Load class. Load serves as
/// a concrete command in the command pattern. The load command either
/// loads a temporary SavedLog from the Logs object or uses the Logs object
/// to load a log stored on disk.
///
//===----------------------------------------------------------------------===//


#include "Load.h"
void Load::execute() {
  if (file!= nullptr){
    execute(file);
    return;
  }
  commandLog->load(logs->loadTemp());
}
void Load::execute(std::string* file) {
  commandLog->load(logs->loadFromFile(*file));
}

Load::Load(CommandLog* commandLog,Logs* logs,std::string* file) {
  if (file == nullptr) {
    this->file = nullptr;
  } else {
    this->file = new std::string(*file);
  }
  this->commandLog = commandLog;
  this->logs = logs;
}
UserCommand *Load::clone() {
  return new Load(commandLog,logs,file);
}
COMMANDS Load::getType() {
  return COMMANDS::LOAD;
}
Load::~Load() {
  delete file;
}
