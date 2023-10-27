//===-- COS214_Project/Logs.h - Logs class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the Logs class. Logs serves as a
/// caretaker in the memento design pattern. It is used to store temporary
/// SavedLogs and to save and load SavedLogs to disk.
///
//===----------------------------------------------------------------------===//


#ifndef COS214_PROJECT__LOGS_H
#define COS214_PROJECT__LOGS_H

#include "SavedLog.h"
#include <map>

class Logs {
private:
  std::map<std::string,SavedLog> saves;
  SavedLog temp;
 public:
  void dumpToFile(std::string file);
  SavedLog loadFromFile(std::string file);
  void tempSave(SavedLog save);
  SavedLog loadTemp();
  Logs();
};

#endif //COS214_PROJECT__LOGS_H
