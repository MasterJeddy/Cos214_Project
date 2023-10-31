#include <gtest/gtest.h>
#include "../InputPoll.h"
//
// Created by maili on 2023/10/23.
//
TEST(ExampleTests,Test1){
    ASSERT_EQ(5,3+2);
}

TEST(SimonTests,CreateAndDeleteInputPoll){
    auto* inputPoll = new InputPoll();
    ASSERT_NE(inputPoll, nullptr);
    delete inputPoll;
}

TEST(SimonTests,InputPollPoll){
  // Create pipe to mock stdin
  int fildes[2];
  int status = pipe(fildes);
  ASSERT_NE(status, -1);

  // Swap `stdin` fd with the "read" end of the pipe
  status = dup2(fildes[0], STDIN_FILENO);
  ASSERT_NE(status, -1);

  // Create payload
  const char buf[] = "1\n1\n1\n1\n1\n1\n1\n1\n2\nq\n";
  const int bsize  = strlen(buf);

  // Send payload through pipe
  ssize_t nbytes = write(fildes[1], buf, bsize);
  close(fildes[1]);
  ASSERT_EQ(nbytes, bsize);

  //Actual Test
  auto* inputPoll = new InputPoll();
  inputPoll->poll();
  delete inputPoll;

  //Close pipe
  close(fildes[0]);
}