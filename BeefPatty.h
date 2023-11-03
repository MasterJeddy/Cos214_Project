//===-- COS214_Project/BeefPatty.h - BeefPatty class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the BeefPatty class. The beefPatty is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_BEEFPATTY_H
#define COS214_PROJECT_BEEFPATTY_H
#include "Patty.h"

class BeefPatty: public Patty {
public:
    BeefPatty();
    ~BeefPatty() override;
};


#endif //COS214_PROJECT_BEEFPATTY_H
