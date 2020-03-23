#include <iostream>
#include "Queue.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  Queue<int> queue;
  bool empty = queue.isEmpty();
  EXPECT_EQ(empty, true);

  const int N = 5;
  for (int i = 0; i < N; i++) {
    queue.push(i + 1);
  }

  int front1 = queue.front();
  EXPECT_EQ(front1, 5);
  
  queue.pop();
  int front2 = queue.front();
  EXPECT_EQ(front2, 4);

  int back = queue.back();
  EXPECT_EQ(back, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
