#include <gtest/gtest.h>
#include "../Clock.h"

#include "../SubBill.h"
#include "../BillComposite.h"
#include "../TableState.h"
#include "../Occupied.h"
#include "../Free.h"

//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests,Test1){
    ASSERT_EQ(5,3+2);
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

TEST(MihailsTests, BillTest){


    SubBill item1("Item 1", 10.50);
    SubBill item2("Item 2", 7.25);

    BillComposite subBill("Sub-Bill 1");
    subBill.add(&item1);
    subBill.add(&item2);

    SubBill item3("Item 3", 5.75);

    BillComposite mainBill("Main Bill");
    mainBill.add(&subBill);
    mainBill.add(&item3);
    
    ASSERT_EQ(mainBill.getTotal(), 23.50)<<"Bill system not working - total calculated incorrectly";



}


TEST(MihailsTests, StateTest){
  //test to check whether the transitions are working correctly 
  
  TableComposite* tableComp = new TableComposite(1);
  TableState* tableState = new Free();
  
  
  ASSERT_EQ(tableState->getName(), "Free")<<"State naming not working as expected.";  

  tableState->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Occupied")<<"State naming not working as expected.";  
  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnWaiter")<<"State naming not working as expected.";  

  tableComp->getTableState()->hold(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Busy")<<"State naming not working as expected.";  

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnWaiter")<<"State naming not working as expected.";  

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "WaitingOnFood")<<"State naming not working as expected.";  

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Eating")<<"State naming not working as expected.";  

  tableComp->getTableState()->proceed(tableComp);
  ASSERT_EQ(tableComp->getTableState()->getName(), "Bill")<<"State naming not working as expected.";  

  
  

} 


TEST(MihailsTests, TableCompositeTest){

  TableComposite* tableComp = new TableComposite(1);
  ASSERT_EQ(tableComp->getId(), "TC_1")<<"ID not working";

  TableComposite* secondTableComp = new TableComposite(2);
  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getChild("TC_2"), secondTableComp);

  //testing whether the remove function works
  tableComp->removeComponent(secondTableComp);
  
  //ASSERT_EQ(tableComp->getChild("TC_2"), "")<<"getChild() behaved unexpectedly...";
  ASSERT_EQ(tableComp->getChild("TC_2"), nullptr);
 
  ASSERT_EQ(tableComp->getCapacity(), 4);

  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 6);
  


}

