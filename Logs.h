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
  /// \brief Serialize SavedLog to disk
  /// \param file Name of file to serialise to Note: .dat will be add from
  void dumpToFile(std::string& file);
  /// \brief Deserialize SavedLog from disk
  /// \param file Name of file to deserialized to Note: .dat will be add from
  /// \return This is the deserialized SavedLog
  SavedLog * loadFromFile(std::string& file);
  /// \brief Save SavedLog to memory
  /// \param save SavedLog to save
  void tempSave(SavedLog* save);
  /// \brief Load SavedLog from memory
  /// \return Last log to be saved to memory
  SavedLog * loadTemp();
  /// \brief Constructor of the Logs class
  Logs();
  /// \brief Destructor of the Logs class
  ~Logs();
};

#endif //COS214_PROJECT__LOGS_H
