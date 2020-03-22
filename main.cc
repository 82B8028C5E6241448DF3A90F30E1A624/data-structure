#include <iostream>
#include "SequentialList.h"
#include "gtest/gtest.h"

int foo(int value) {
  static int i = 0;
  i++;
  return i;
}

TEST(Suite1, Test1) {
  const int N = 8;
  SequentialList<int> list;
  int i;
  for (i = 0; i < N; i++) {
    list.insert(i + 1);
  }
  EXPECT_EQ(list.insert(i + 1), false);

  int n = 0;
  for (int d : list) {
    n++;
    EXPECT_EQ(d, n);
  }
  EXPECT_EQ(n, 8);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
