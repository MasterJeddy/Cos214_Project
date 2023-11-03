#include <gtest/gtest.h>
#include "../Clock.h"
#include "../Burger.h"
#include "../BurgerBuns.h"
#include "../Kitchen.h"

#include "../Ketchup.h"
#include "../Tomato.h"
//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests,Test1){
    ASSERT_EQ(5,3+2);
}

TEST(SimonTests,ClockGetTimeAndTickTest){
  ASSERT_EQ(Clock::instance().getTime("a"),0) << "New timer not equal 0";
  ASSERT_EQ(Clock::instance().getTime("b"),0) << "New timer not equal 0";
  ASSERT_EQ(Clock::instance().getTime("c"),0) << "New timer not equal 0";

  ASSERT_EQ(Clock::instance().getTime("a"),0) << "Clock did no stay 0 on next check";
  ASSERT_EQ(Clock::instance().getTime("b"),0) << "Clock did no stay 0 on next check";
  ASSERT_EQ(Clock::instance().getTime("c"),0) << "Clock did no stay 0 on next check";

  Clock::instance().tick();

  ASSERT_EQ(Clock::instance().getTime("a"),1) << "Clock did not go up to 1 after 1 tick";
  ASSERT_EQ(Clock::instance().getTime("b"),1) << "Clock did not go up to 1 after 1 tick";
  ASSERT_EQ(Clock::instance().getTime("c"),1) << "Clock did not go up to 1 after 1 tick";

  ASSERT_EQ(Clock::instance().getTime("d"),0) << "New timer not equal 0";


  ASSERT_EQ(Clock::instance().getTime("a"),1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("b"),1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("c"),1) << "Creating new timer effected old ones";
  ASSERT_EQ(Clock::instance().getTime("d"),0) << "Clock did no stay 0 on next check";

  Clock::instance().tick();

  ASSERT_EQ(Clock::instance().getTime("a"),2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("b"),2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("c"),2) << "Clock did not go up to 2 after 2 ticks";
  ASSERT_EQ(Clock::instance().getTime("d"),1) << "Clock did not go up to 1 after 1 tick";
}

TEST(SimonTests,ClockRemoveTimeAndHasTimeTest) {
    //Apparently needed to make this test independent of the first one
    Clock::instance().removeTime("a");
    Clock::instance().removeTime("b");
    Clock::instance().removeTime("c");
    //Setup
    ASSERT_EQ(Clock::instance().getTime("a"),0) << "Tests are interfering with each other";
    Clock::instance().tick();
    ASSERT_EQ(Clock::instance().getTime("b"),0) << "Tests are interfering with each other";
    Clock::instance().tick();
    ASSERT_EQ(Clock::instance().getTime("c"),0) << "Tests are interfering with each other";

    ASSERT_EQ(Clock::instance().getTime("a"),2) << "Setup Failed";
    ASSERT_EQ(Clock::instance().getTime("b"),1) << "Setup Failed";
    ASSERT_EQ(Clock::instance().getTime("c"),0) << "Setup Failed";
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