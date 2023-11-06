//===-- COS214_Project/Save.h - Save class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the Save class. Save serves as
/// a concrete command in the command pattern. The save command either
/// creates a temporary SavedLog in the Logs object or use the Logs object
/// to store a SavedLog on disk.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__SAVE_H
#define COS214_PROJECT__SAVE_H

#include <string>
#include "UserCommand.h"
#include "CommandLog.h"
#include "Logs.h"

class Save : public UserCommand{
private:
  std::string* file;
  CommandLog* commandLog;
  Logs* logs;
public:
  /// \brief If file member is set save to disk else save to memory.
  void execute() override;
  /// \brief Save to disk
  /// \param file
  void execute(std::string* file);
  /// \brief Constructor of Save class.
  /// \param commandLog CommandLog to save
  /// \param logs Logs to save to
  /// \param file File to save to. If nullptr save to memory
  explicit Save(CommandLog* commandLog,Logs* logs,std::string* file = nullptr);
  /// \brief Destructor for save Class
  ~Save() override;
  /// \brief Makes a copy of Save
  /// \return Pointer to the copy of Save
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return SAVE ENUM returned
  COMMANDS getType() override;
};


#endif //COS214_PROJECT__SAVE_H
