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

#include "UserCommand.h"
class Save : public UserCommand{

};

#endif //COS214_PROJECT__SAVE_H
