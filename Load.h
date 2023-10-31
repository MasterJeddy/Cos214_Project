//===-- COS214_Project/Load.h - Load class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the Load class. Load serves as
/// a concrete command in the command pattern. The load command either
/// loads a temporary SavedLog from the Logs object or uses the Logs object
/// to load a log stored on disk.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__LOAD_H
#define COS214_PROJECT__LOAD_H

#include <string>
#include "UserCommand.h"
#include "Logs.h"
class Load : public  UserCommand{
private:
  std::string* file;
  CommandLog* commandLog;
  Logs* logs;
public:
  void execute() override;
  void execute(std::string* file);
  explicit Load(CommandLog* commandLog,Logs* logs,std::string* file = nullptr);
  UserCommand *clone() override;
  COMMANDS getType() override;
  ~Load() override;
};

#endif //COS214_PROJECT__LOAD_H
