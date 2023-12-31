//
// Created by nield on 2023/10/26.
//

#ifndef COS214_PROJECT__KITCHEN_H
#define COS214_PROJECT__KITCHEN_H

//===-- COS214_Project/Kitchen.h - Kitchen class definition ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Kitchen class,
/// functioning as a singleton.
/// \brief Class containing the systems of the kitchen and will
/// be in charge of its operations.
///
//===----------------------------------------------------------------------===//

#include "HeadChef.h"
#include "KitchenSubject.h"
struct Order;

class Kitchen : public KitchenSubject
{
private:
  static Kitchen *instance;

  HeadChef headChef;
  bool isBusy = false;

  Kitchen();
  ~Kitchen();
  Kitchen(Kitchen &);
  Kitchen &operator=(Kitchen &);

public:
  /// \brief Gives you the Kitchen singleton object instance
  /// \return Kitchen instance, creates one if there isn't one already
  static Kitchen *getInstance();

  /// \brief Adds a new order to the queue of orders which will be handled by the chefs
  /// \param order A pointer to a new order struct,
  /// \return true if added successfully, can be run like a void method
  bool addOrder(Order *order);

  /// \brief All orders returned have their counters for ingredients set to 0 (hopefully)
  /// \return the oldest finished order produced by the chefs
  Order *getFinishedOrder();

  /// \brief Starts burger production for one cycle through all the chefs
  void produceBurgers();

  /// \brief Increases the maximum amount of orders the team of chefs can work on at once
  void purchaseChef();
  friend class IOInterfaceGUI;

  // functions for the applied observer pattern
  /// \brief Notifies all waiters attached to the observer list that orders are finished
  virtual void notifyWaiter();
  /// \brief Adds a waiter to the observer list
  /// \param waiter Waiter object to be attached
  virtual void attach(Waiter *waiter);
  /// \brief Removes a waiter from the observer list
  /// \param waiter Waiter object to be removed
  virtual void detach(Waiter *waiter);

  /// \brief Resets the kitchen
  void reset();
};

#endif // COS214_PROJECT__KITCHEN_H
