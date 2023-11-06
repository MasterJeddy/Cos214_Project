//===-- COS214_Project/ChickenPatty.h - ChickenPatty class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ChickenPatty class. The chickenPatty is a
/// Concrete decorator in the decorator pattern that will be one of the ingredients
/// the burger that be made up of.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT_CHICKENPATTY_H
#define COS214_PROJECT_CHICKENPATTY_H
#include "Patty.h"

class ChickenPatty: public Patty{
public:
  /// \brief The constructor for the ChickenPatty class
    ChickenPatty();
  /// \brief The destructor for the ChickenPatty class
    ~ChickenPatty() override;
};


#endif //COS214_PROJECT_CHICKENPATTY_H
