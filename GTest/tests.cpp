#include <gtest/gtest.h>
#include "../Clock.h"

//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests,Test1){
    ASSERT_EQ(5,3+2);
}

TEST(SimonTests,ClockTestBasicCount){
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