//===-- COS214_Project/Commands.cpp - Commands class implementations ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the implementation of several concrete commands in the
/// command pattern. Specifically HireMaitreD, BuyTable, ExpandFloor,
/// HireWaiter, ExpandKitchen, HireChef and BuyStock. What these commands
/// all have in common is that they will simple call corresponding functions
/// on the KitchenController and FloorController facades. e.g. BuyStock will
/// call the buyStock method on KitchenController.
///
//===----------------------------------------------------------------------===//

#include "Commands.h"
