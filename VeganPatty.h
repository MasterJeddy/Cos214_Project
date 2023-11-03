//===-- COS214_Project/VeganPatty.h - VeganPatty class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the VeganPatty class. The veganPatty is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_VEGANPATTY_H
#define COS214_PROJECT_VEGANPATTY_H
#include "Patty.h"

class VeganPatty: public Patty{
public:
    VeganPatty();
    ~VeganPatty() override;
};


#endif //COS214_PROJECT_VEGANPATTY_H
