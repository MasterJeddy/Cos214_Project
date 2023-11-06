//===-- COS214_Project/FloorController.h - FloorController class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the FloorController class
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_FLOORCONTROLLER_H
#define COS214_PROJECT_FLOORCONTROLLER_H

#include "Floor.h"

class FloorController
{
public:
    /// \brief hires a waiter
    void hireWaiter();
    /// \brief updates Floor
    void update();
    /// \brief hires a maitre D
    void hireMaitreD();
    /// \brief buys a Table
    void buyTable();
    /// \brief expands Floor
    void expandFloor();
    /// \brief resets floor subsystem
    void reset();
};

#endif