#include <gtest/gtest.h>

//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests,Test1){
    ASSERT_EQ(5,3+2);
}

#include "../TableState.h"
#include "../Free.h"

TEST(MihailsTests, StateTest){

    TableState* tempy = new TableState();
    //TableState* freestate = new Free();
    ASSERT_EQ(tempy->getName(), null);



}