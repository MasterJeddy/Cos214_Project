#include <gtest/gtest.h>
#include "../Clock.h"
#include "../Burger.h"
#include "../BurgerBuns.h"
#include "../Kitchen.h"

#include "../SubBill.h"
#include "../BillComposite.h"
#include "../TableState.h"
#include "../Occupied.h"
#include "../Free.h"

#include "../Floor.h"
#include "../IOInterface.h"

#include "../Ketchup.h"
#include "../Tomato.h"
//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests, Test1)
{
  ASSERT_EQ(5, 3 + 2);
}

TEST(SimonTests, ClockGetTimeAndTickTest)
{
  ASSERT_EQ(Clock::instance().getTime("a"), 0) << "New timer not equal 0";
  ASSERT_EQ(Clock::instance().getTime("b"), 0) << "New timer not equal 0";
  ASSERT_EQ(Clock::instance().getTime("c"), 0) << "New timer not equal 0";

  ASSERT_EQ(Clock::instance().getTime("a"), 0) << "Clock did no stay 0 on next check";
  ASSERT_EQ(Clock::instance().getTime("b"), 0) << "Clock did no stay 0 on next check";
  ASSERT_EQ(Clock::instance().getTime("c"), 0) << "Clock did no stay 0 on next check";

  Clock::instance().tick();

  ASSERT_EQ(Clock::instance().getTime("a"), 1) << "Clock did not go up to 1 after 1 tick";
  ASSERT_EQ(Clock::instance().getTime("b"), 1) << "Clock did not go up to 1 after 1 tick";
  ASSERT_EQ(Clock::instance().getTime("c"), 1) << "Clock did not go up to 1 after 1 tick";

  ASSERT_EQ(Clock::instance().getTime("d"), 0) << "New timer not equal 0";

  ASSERT_EQ(Clock::instance().getTime("a"), 1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("b"), 1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("c"), 1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("d"), 0) << "Clock did no stay 0 on next check";

  Clock::instance().tick();

  ASSERT_EQ(Clock::instance().getTime("a"), 2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("b"), 2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("c"), 2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("d"), 1) << "Clock did not go up to 1 after 1 tick";
}

TEST(SimonTests, ClockRemoveTimeAndHasTimeTest)
{
  // Apparently needed to make this test independent of the first one
  Clock::instance().removeTime("a");
  Clock::instance().removeTime("b");
  Clock::instance().removeTime("c");
  // Setup
  ASSERT_EQ(Clock::instance().getTime("a"), 0) << "Tests are interfering with each other";
  Clock::instance().tick();
  ASSERT_EQ(Clock::instance().getTime("b"), 0) << "Tests are interfering with each other";
  Clock::instance().tick();
  ASSERT_EQ(Clock::instance().getTime("c"), 0) << "Tests are interfering with each other";

  ASSERT_EQ(Clock::instance().getTime("a"), 2) << "Setup Failed";
  ASSERT_EQ(Clock::instance().getTime("b"), 1) << "Setup Failed";
  ASSERT_EQ(Clock::instance().getTime("c"), 0) << "Setup Failed";
  // If we reach this point then both hasTime and removeTime work as expected
  // I have however broken the wisdom of the gtest documentation by indirectly
  // using ClockGetTimeAndTickTest for this test
}

TEST(GeordanTest,test1){
    BurgerBuns* bun = new BurgerBuns();
    std::cout << bun->totalPrice() << "\n";
    Ketchup* ing1 = new Ketchup();
    ing1->add(bun);
    std::cout << ing1->totalPrice() << "\n";
    Tomato* ing2 = new Tomato();
    ing2->add(ing1);
    std::cout << ing2->totalPrice() << "\n";
}

int orderStatus(Order* order) {
  int sum = order->beefPatty + order->chickenPatty + order->veganPatty
      + order->wantsKetchup + order->wantsMustard + order->wantsMayo;
  sum += order->wantsLettuce + order->wantsPickles + order->wantsTomato;
  return sum;
}
TEST(NielTests, ChefChainTest) {

  // first test; should be done in 3 ticks:
  Order* testOrder1 = new Order("table-1");
  testOrder1->beefPatty = 1;

  // second test; should be done in 3 ticks
  Order* testOrder2 = new Order("table-2");
  testOrder2->chickenPatty = 1;
  testOrder2->wantsTomato = 1;
  testOrder2->wantsLettuce = 1;

  // third test; should be done in 3 ticks (tests all chefs)
  Order* testOrder3 = new Order("table-3");
  testOrder3->beefPatty = 1;
  testOrder3->chickenPatty = 1;
  testOrder3->veganPatty = 1;

  testOrder3->wantsMustard = 1;
  testOrder3->wantsKetchup = 1;
  testOrder3->wantsMayo = 1;

  testOrder3->wantsLettuce = 1;
  testOrder3->wantsTomato = 1;
  testOrder3->wantsPickles = 1;

  // fourth test; should be done in 6 ticks
  Order* testOrder4 = new Order("table-4");
  testOrder4->wantsPickles = 2;
  testOrder4->wantsKetchup = 2;

  Order* testOrder5 = new Order("table-5");
  testOrder4->wantsMustard = 2;
  testOrder4->beefPatty = 2;

  // sixth test; should be done in 9 ticks (tests all chefs)
  Order* testOrder6 = new Order("table-6");
  testOrder3->beefPatty = 3;
  testOrder3->chickenPatty = 3;
  testOrder3->veganPatty = 3;

  testOrder3->wantsMustard = 3;
  testOrder3->wantsKetchup = 3;
  testOrder3->wantsMayo = 3;

  testOrder3->wantsLettuce = 3;
  testOrder3->wantsTomato = 3;
  testOrder3->wantsPickles = 3;


  Kitchen::getInstance()->addOrder(testOrder1);
  Kitchen::getInstance()->addOrder(testOrder2);
  Kitchen::getInstance()->addOrder(testOrder3);
  Kitchen::getInstance()->addOrder(testOrder4);
  Kitchen::getInstance()->addOrder(testOrder5);
  Kitchen::getInstance()->addOrder(testOrder6);

  // game continues for 3 ticks
  for (int i = 0; i < 12; i++) {
    Kitchen::getInstance()->produceBurgers();
    Clock::instance().tick();
  }

  // tests for order 1
  Order* order1Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order1Result), 0);

  // tests for order 2
  Order* order2Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order2Result), 0);

  // tests for order 3
  Order* order3Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order3Result), 0);

  // tests for order 4
  Order* order4Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order4Result), 0);

  // tests for order 5
  Order* order5Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order5Result), 0);

  // tests for order 6
  Order* order6Result = Kitchen::getInstance()->getFinishedOrder();
  ASSERT_EQ(orderStatus(order6Result), 0);

}

TEST(MihailsTests, BillTest)
{

  BillComponent *billComp = new SubBill("CheeseBurger", 12);
  BillComponent *billComp2 = new SubBill("Fries", 8);
  BillComponent *billComp3 = new BillComposite("MainBill");
  billComp3->add(billComp2);
  billComp3->add(billComp);
  ASSERT_EQ(billComp3->getTotal(), 20);

  // memory cleanup
  delete billComp3;
}

TEST(MihailsTests, StateTest)
{
  // test to check whether the transitions are working correctly

  TableComposite *tableComp = new TableComposite(1);
  TableState *tableState = new Free();
  tableComp->setTableState(tableState);

  ASSERT_EQ(tableState->getName(), "Free") << "State naming not working as expected.";

  tableState->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Occupied") << "State naming not working as expected.";
  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnWaiter") << "State naming not working as expected.";

  tableComp->getTableState()->hold(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Busy") << "State naming not working as expected.";

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnWaiter") << "State naming not working as expected.";

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnFood") << "State naming not working as expected.";

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Eating") << "State naming not working as expected.";

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Bill") << "State naming not working as expected.";

  // memory cleanup
  delete tableComp;
}

TEST(MihailsTests, TableCompositeTest)
{

  TableComposite *tableComp = new TableComposite(1);
  ASSERT_EQ(tableComp->getId(), "TC_1") << "ID not working";

  TableComposite *secondTableComp = new TableComposite(2);
  TableComposite *thirdTableComp = new TableComposite(3);
  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getChild("TC_2"), secondTableComp);

  // testing whether the remove function works
  tableComp->removeComponent(secondTableComp);

  // ASSERT_EQ(tableComp->getChild("TC_2"), "")<<"getChild() behaved unexpectedly...";
  ASSERT_EQ(tableComp->getChild("TC_2"), nullptr);

  ASSERT_EQ(tableComp->getCapacity(), 4);

  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 6);

  tableComp->addComponent(thirdTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->removeComponent(thirdTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 6);

  TableComposite *fourthTableComp = new TableComposite(4);
  TableComposite *fifthTableComp = new TableComposite(5);

  tableComp->addComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->addComponent(fifthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 10);

  tableComp->removeComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->addComponent(fourthTableComp);
  tableComp->removeComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  // do memory cleanup
  delete thirdTableComp;
  delete fourthTableComp;
  delete tableComp;
}

TEST(TinoTests, FloorIsASingleton)
{
  // Floor *floor = Floor::instance();
  // Floor *floor = Floor::instance();
}

TEST(SimonTests, CreateAndDeleteInputPoll)
{
  auto *inputPoll = new IOInterface();
  ASSERT_NE(inputPoll, nullptr);
  delete inputPoll;
}

TEST(SimonTests, InputPollSaveLoad)
{
  // Create pipe to mock stdin
  int fildes[2];
  int status = pipe(fildes);
  ASSERT_NE(status, -1);

  // Swap `stdin` fd with the "read" end of the pipe
  status = dup2(fildes[0], STDIN_FILENO);
  ASSERT_NE(status, -1);

  // Create payload
  const char buf[] = "1\n1\n1\n1\n1\n1\n1\n1\n2\nq\n";
  const int bsize = strlen(buf);

  // Send payload through pipe
  ssize_t nbytes = write(fildes[1], buf, bsize);
  close(fildes[1]);
  ASSERT_EQ(nbytes, bsize);

  // Actual Test
  auto *inputPoll = new IOInterface();
  inputPoll->poll();
  delete inputPoll;

  // Close pipe
  close(fildes[0]);
}

TEST(SimonTests, InputPollMixedSaveMixedLoad)
{
  // Create pipe to mock stdin
  int fildes[2];
  int status = pipe(fildes);
  ASSERT_NE(status, -1);

  // Swap `stdin` fd with the "read" end of the pipe
  status = dup2(fildes[0], STDIN_FILENO);
  ASSERT_NE(status, -1);

  // Create payload
  const char buf[] = "7\n5\n7\n5\n5\n6\n6\n1\n5\n6\n7\n8\n9\nA\nB\n5\n5\n5\n2\n6\n6\nq\n";
  const int bsize  = strlen(buf);

  // Send payload through pipe
  ssize_t nbytes = write(fildes[1], buf, bsize);
  close(fildes[1]);
  ASSERT_EQ(nbytes, bsize);

  // Actual Test
  auto *inputPoll = new IOInterface();
  inputPoll->poll();
  delete inputPoll;

  // Close pipe
  close(fildes[0]);
}

TEST(SimonTests, SaveToFile)
{
  // Create pipe to mock stdin
  int fildes[2];
  int status = pipe(fildes);
  ASSERT_NE(status, -1);

  // Swap `stdin` fd with the "read" end of the pipe
  status = dup2(fildes[0], STDIN_FILENO);
  ASSERT_NE(status, -1);

  // Create payload
  const char buf[] = "5\n7\n5\n5\n7\n5\n9\n1\n3\ntoets\nq\n";
  const int bsize = strlen(buf);

  // Send payload through pipe
  ssize_t nbytes = write(fildes[1], buf, bsize);
  close(fildes[1]);
  ASSERT_EQ(nbytes, bsize);

  // Actual Test
  auto *inputPoll = new IOInterface();
  inputPoll->poll();
  delete inputPoll;

  // Close pipe
  close(fildes[0]);
}

TEST(SimonTests, LoadFromFile)
{
  // Create pipe to mock stdin
  int fildes[2];
  int status = pipe(fildes);
  ASSERT_NE(status, -1);

  // Swap `stdin` fd with the "read" end of the pipe
  status = dup2(fildes[0], STDIN_FILENO);
  ASSERT_NE(status, -1);

  // Create payload
  const char buf[] = "1\n4\ntoets\nq\n";
  const int bsize = strlen(buf);

  // Send payload through pipe
  ssize_t nbytes = write(fildes[1], buf, bsize);
  close(fildes[1]);
  ASSERT_EQ(nbytes, bsize);

  // Actual Test
  auto *inputPoll = new IOInterface();
  inputPoll->poll();
  delete inputPoll;

  // Close pipe
  close(fildes[0]);
}









TEST(MihailsTests, TableStateChildrenTest){
    //this will test whether the children of the table will
    // be set to the relevant state when combining tables
    // as well as separating tables from each other

    TableComposite* mainTable = new TableComposite(1);
    TableComposite* childTable1 = new TableComposite(2);
    mainTable->addComponent(childTable1);
    // //create a state
    TableState* ts = new Bill();
    mainTable->setTableState(ts);
    ASSERT_EQ(mainTable->getChild("TC_2")->getTableState()->getName(), "Bill");
    // mainTable->removeComponent(childTable1);
    // ASSERT_EQ(childTable1->getTableState()->getName(), "Free");

    // mainTable
    // mainTable->getPayment();

    //Clear memory

}




