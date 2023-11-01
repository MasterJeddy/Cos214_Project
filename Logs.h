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
  std::map<std::string,SavedLog>* saves;
  SavedLog* temp;
 public:
  /// \brief
  /// \param file
  void dumpToFile(std::string& file);
  /// \brief
  /// \param file
  /// \return
  SavedLog * loadFromFile(std::string& file);
  /// \brief
  /// \param save
  void tempSave(SavedLog* save);
  /// \brief
  /// \return
  SavedLog * loadTemp();
  /// \brief
  Logs();
  /// \brief
  ~Logs();
};

#endif //COS214_PROJECT__LOGS_H
