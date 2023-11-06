//===-- COS214_Project/Update.h - Update class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of the Update class. Update serves
/// as the concrete command in the command design. It is the most important
/// command in the entire system as it tells the entire system to move one
/// step forward. It is the class that triggers all the other classes.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__UPDATE_H
#define COS214_PROJECT__UPDATE_H

#include "UserCommand.h"
class Update : public UserCommand{
private:
  FloorController* floorController;
  KitchenController* kitchenController;
public:
  /// \brief Lets clock tick and calls update on floorController and kitchenController members.
  void execute() override;
  /// \brief Makes a copy of Update
  /// \return Pointer to the copy of Update
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return SAVE ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of Update
  ~Update() override;
  /// \brief Constructor for Update Class
  /// \param floorController FloorController to call methods on
  /// \param kitchenController KitchenController to call methods on
  explicit Update(FloorController* floorController,KitchenController* kitchenController);
};

#endif //COS214_PROJECT__UPDATE_H
