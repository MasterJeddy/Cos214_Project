//===-- COS214_Project/Save.cpp - Save class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of the Save class. Save serves as
/// a concrete command in the command pattern. The save command either
/// creates a temporary SavedLog in the Logs object or use the Logs object
/// to store a SavedLog on disk.
///
//===----------------------------------------------------------------------===//
#include "Save.h"
void Save::execute() {
    if (file!= nullptr)
    {
      execute(file);
      return;
    }
    logs->tempSave(commandLog->save());
}

void Save::execute(std::string* file) {
  logs->dumpToFile(*file);
}

Save::Save(CommandLog* commandLog,Logs* logs,std::string* file) {
    if (file == nullptr) {
      this->file = nullptr;
    } else {
      this->file = new std::string(*file);
    }
    this->commandLog = commandLog;
    this->logs = logs;
}
Save::~Save() {
    delete file;
}

UserCommand *Save::clone() {
  return new Save(commandLog,logs,file);
}