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


  
    BillComponent* billComp = new SubBill("CheeseBurger", 12);
    BillComponent* billComp2 = new SubBill("Fries", 8);
    BillComponent* billComp3 = new BillComposite("MainBill");
    billComp3->add(billComp2);
    billComp3->add(billComp);
    ASSERT_EQ(billComp3->getTotal(), 20);


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
  TableComposite* thirdTableComp = new TableComposite(3);
  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getChild("TC_2"), secondTableComp);

  //testing whether the remove function works
  tableComp->removeComponent(secondTableComp);
  
  //ASSERT_EQ(tableComp->getChild("TC_2"), "")<<"getChild() behaved unexpectedly...";
  ASSERT_EQ(tableComp->getChild("TC_2"), nullptr);
 
  ASSERT_EQ(tableComp->getCapacity(), 4);

  tableComp->addComponent(secondTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 6);

  tableComp->addComponent(thirdTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->removeComponent(thirdTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 6);

  TableComposite* fourthTableComp = new TableComposite(4);
  TableComposite* fifthTableComp = new TableComposite(5);

  tableComp->addComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->addComponent(fifthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 10);

  tableComp->removeComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);

  tableComp->addComponent(fourthTableComp);
  tableComp->removeComponent(fourthTableComp);
  ASSERT_EQ(tableComp->getCapacity(), 8);



  


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
}




