#include <iostream>
#include "Stack.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  Stack<int> list;
  EXPECT_EQ(list.isEmpty(), true);

  const int N = 5;
  for (int i = 0; i < N; i++) {
    list.push(i + 1);
  }
  EXPECT_EQ(list.top(), 5);
  list.pop();
  EXPECT_EQ(list.top(), 4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
