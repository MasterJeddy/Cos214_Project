//===-- COS214_Project/Commands.h - Commands class definitions ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===/////
/// \file
/// This file contains the declaration of several concrete commands in the
/// command pattern. Specifically HireMaitreD, BuyTable, ExpandFloor,
/// HireWaiter, ExpandKitchen, HireChef and BuyStock. What these commands
/// all have in common is that they will simple call corresponding functions
/// on the KitchenController and FloorController facades. e.g. BuyStock will
/// call the buyStock method on KitchenController.
///
//===----------------------------------------------------------------------===//

#ifndef COS214_PROJECT__COMMANDS_H
#define COS214_PROJECT__COMMANDS_H

#include "UserCommand.h"
#include "IOInterface.h"

class FloorController;
class KitchenController;

class HireMaitreD : public UserCommand{
private:
  FloorController* floorController;
public:
  /// \brief Calls hireMaitreD on the floorController member
  void execute() override;
  /// \brief Makes a copy of HireMaitreD
  /// \return Pointer to the copy of HireMaitreD
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return HIRE_MAITRE_D ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of HireMaitreD
  ~HireMaitreD() override;
  /// \brief The constructor for HireMaitreD
  /// \param floorController FloorController to call methods on
  explicit HireMaitreD(FloorController* floorController);
};

class BuyTable : public UserCommand{
private:
  FloorController* floorController;
public:
  /// \brief Calls buyTable on the floorController member
  void execute() override;
  /// \brief Makes a copy of BuyTable
  /// \return Pointer to the copy of BuyTable
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return BUY_TABLE ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of BuyTable
  ~BuyTable() override;
  /// \brief The constructor for BuyTable
  /// \param floorController FloorController to call methods on
  explicit BuyTable(FloorController* floorController);
};

class ExpandFloor : public UserCommand{
private:
  FloorController* floorController;
public:
  /// \brief Calls expandFloor on the floorController member
  void execute() override;
  /// \brief Makes a copy of ExpandFloor
  /// \return Pointer to the copy of ExpandFloor
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return EXPAND_FLOOR ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of ExpandFloor
  ~ExpandFloor() override;
  /// \brief The constructor for ExpandFloor
  /// \param floorController FloorController to call methods on
  explicit  ExpandFloor(FloorController* floorController);
};

class HireWaiter : public UserCommand{
private:
  FloorController* floorController;
public:
  /// \brief Calls hireWaiter on the floorController member
  void execute() override;
  /// \brief Makes a copy of HireWaiter
  /// \return Pointer to the copy of HireWaiter
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return HIRE_WAITER ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of HireWaiter
  ~HireWaiter() override;
  /// \brief The constructor for HireWaiter
  /// \param floorController FloorController to call methods on
  explicit HireWaiter(FloorController* floorController);
};

class ExpandKitchen : public UserCommand{
private:
  KitchenController* kitchenController;
public:
  /// \brief Calls expandKitchen on the kitchenController member
  void execute() override;
  /// \brief Makes a copy of ExpandKitchen
  /// \return Pointer to the copy of ExpandKitchen
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return EXPAND_KITCHEN ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of ExpandKitchen
  ~ExpandKitchen() override;
  /// \brief The constructor for ExpandKitchen
  /// \param kitchenController KitchenController to call methods on
  explicit ExpandKitchen(KitchenController* kitchenController);
};

class HireChef : public UserCommand{
private:
  KitchenController* kitchenController;
public:
  /// \brief Calls hireChef on the kitchenController member
  void execute() override;
  /// \brief Makes a copy of HireChef
  /// \return Pointer to the copy of HireChef
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return HIRE_CHEF ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of HireChef
  ~HireChef() override;
  /// \brief The constructor for HireChef
  /// \param kitchenController KitchenController to call methods on
  explicit HireChef(KitchenController* kitchenController);
};

class BuyStock : public UserCommand{
private:
  KitchenController* kitchenController;
public:
  /// \brief Calls buyStock on the kitchenController member
  void execute() override;
  /// \brief Makes a copy of BuyStock
  /// \return Pointer to the copy of BuyStock
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return BUY_STOCK ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of BuyStock
  ~BuyStock() override;
  /// \brief The constructor for BuyStock
  /// \param kitchenController KitchenController to call methods on
  explicit  BuyStock(KitchenController* kitchenController);
};

class ToggleHelp : public UserCommand{
private:
  IOInterface* ioInterface;
public:
  /// \brief Sets the DONT_DRAW_HELP flag on IOInterface if it is not set and sets it if set
  void execute() override;
  /// \brief Makes a copy of ToggleHelp
  /// \return Pointer to the copy of ToggleHelp
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return TOGGLE_HELP ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of ToggleHelp
  ~ToggleHelp() override;
  /// \brief The constructor for ToggleHelp
  /// \param IoInterface IOInterface to set and unset flags on.
  explicit ToggleHelp(IOInterface* IoInterface);
  /// \brief Setter for ioInterface
  /// \param ip New value of ioInterface
  void setIOInterface(IOInterface* ip);
};

class ToggleLog : public UserCommand{
private:
  IOInterface* ioInterface;
public:
  /// \brief Sets the DRAW_LOG flag on IOInterface if it is not set and sets it if set
  void execute() override;
  /// \brief Makes a copy of ToggleLog
  /// \return Pointer to the copy of ToggleLog
  UserCommand *clone() override;
  /// \brief Returns the type of the command
  /// \return TOGGLE_LOG ENUM returned
  COMMANDS getType() override;
  /// \brief Destructor of ToggleLog
  ~ToggleLog() override;
  /// \brief The constructor for ToggleLog
  /// \param IoInterface IOInterface to set and unset flags on.
  explicit ToggleLog(IOInterface* IoInterface);
  /// \brief Setter for ioInterface
  /// \param ip New value of ioInterface
  void setIOInterface(IOInterface* ip);
};


#endif //COS214_PROJECT__COMMANDS_H
