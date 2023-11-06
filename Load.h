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
  /// \brief If file member is set load from disk else load from memory.
  void execute() override;
  /// \brief Loads from disk
  /// \param file
  void execute(std::string* file);
  /// \brief Constructor for Load class.
  /// \param commandLog CommandLog to load to
  /// \param logs Logs to load From
  /// \param file File to Load From. If nullptr will load from save on disk
  explicit Load(CommandLog* commandLog,Logs* logs,std::string* file = nullptr);
  /// \brief Makes a copy of Load
  /// \return Pointer to the copy of Load
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return LOAD ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of Load
  ~Load() override;
};

#endif //COS214_PROJECT__LOAD_H
