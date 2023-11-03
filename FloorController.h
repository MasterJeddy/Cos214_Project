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
    void hireWaiter();
    void update();
    void hireMaitreD();
    void buyTable();
    void expandFloor();
};

#endif