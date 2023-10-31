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
void Logs::dumpToFile(std::string file) {

}
SavedLog Logs::loadFromFile(std::string file) {
  return SavedLog();
}
void Logs::tempSave(SavedLog save) {

}
SavedLog Logs::loadTemp() {
  return SavedLog();
}
Logs::Logs() {

}