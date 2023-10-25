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
