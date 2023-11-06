//
// Created by nield on 2023/10/26.
//

#include "Kitchen.h"
#include "Order.h"
#include "Clock.h"
Kitchen::Kitchen()
{
}

Kitchen *Kitchen::instance = nullptr;

bool Kitchen::addOrder(Order *order)
{
  headChef.addOrder(order);
  // if this at some point becomes a point of failure, a fail condition can be added to return false
  return true;
}

void Kitchen::produceBurgers()
{
  if (Clock::instance().getTime("produceBurger") == 0)
  {
    headChef.startOrders();
    notifyWaiter();
  }
  if (Clock::instance().getTime("produceBurger") > 3)
  {
    Clock::instance().removeTime("produceBurger");

  }

}
Kitchen *Kitchen::getInstance()
{
  if (instance == nullptr)
    instance = new Kitchen();

  return instance;
}
/// \brief Get the next finished order in the finished order queue
/// \return nullptr if no orders are ready to be collected, otherwise returns order*
Order *Kitchen::getFinishedOrder()
{

  return headChef.getFinishedOrder();
}
void Kitchen::purchaseChef()
{
  headChef.increaseMaxOrders();
}
void Kitchen::notifyWaiter()
{
  // get the finished order and pass it to the waiter which then passes to table
  Order *finishedOrder = this->getFinishedOrder();

  // find the waiter taht is responsible for this order
  for (Waiter *waiter : this->waiterList)
  {
    if (waiter->isResponsibleForThisTable(finishedOrder->tableID))
    {
      // notify waiter to take finished order to table
      waiter->takeOrderToFloor(finishedOrder);

      // detach this waiter from being an observer of kitchen since they have taken their order to floor
      this->detach(waiter);
      break;
    }
  }
}
void Kitchen::attach(Waiter *waiter)
{
  this->waiterList.push_back(waiter);
}
void Kitchen::detach(Waiter *waiter)
{
  for (std::vector<Waiter *>::iterator iter = this->waiterList.begin(); iter < this->waiterList.end(); iter++)
  {
    if ((*iter)->getId() == waiter->getId())
    {
      this->waiterList.erase(iter);
      return;
    }
  }
}
void Kitchen::reset() {
    waiterList.clear();
    HeadChef h;
    headChef = h;
}


Kitchen::~Kitchen() = default;
Kitchen::Kitchen(Kitchen &) = default;
Kitchen &Kitchen::operator=(Kitchen &) = default;
