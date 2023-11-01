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

class HireMaitreD : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~HireMaitreD() override;

};

class BuyTable : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~BuyTable() override;
};

class ExpandFloor : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~ExpandFloor() override;

};

class HireWaiter : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~HireWaiter() override;
};

class ExpandKitchen : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~ExpandKitchen() override;
};

class HireChef : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~HireChef() override;
};

class BuyStock : public UserCommand{
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~BuyStock() override;
};

class ToggleHelp : public UserCommand{
private:
  IOInterface* inputPoll;
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~ToggleHelp() override;
  /// \brief
  /// \param inputPoll
  explicit ToggleHelp(IOInterface* inputPoll);
  /// \brief
  /// \param ip
  void setInputPoll(IOInterface* ip);
};

class ToggleLog : public UserCommand{
private:
  IOInterface* inputPoll;
public:
  /// \brief
  void execute() override;
  /// \brief
  /// \return
  UserCommand *clone() override;
  /// \brief
  /// \return
  COMMANDS getType() override;
  /// \brief
  ~ToggleLog() override;
  /// \brief
  /// \param inputPoll
  explicit ToggleLog(IOInterface* inputPoll);
  /// \brief
  /// \param ip
  void setInputPoll(IOInterface* ip);
};


#endif //COS214_PROJECT__COMMANDS_H
