#include <iostream>
#include "LinkList.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  LinkList<int> list;
  EXPECT_EQ(list.isEmpty(), true);

  const int N = 5;
  for (int i = 0; i < N; i++) {
    list.insert(1);
  }

  EXPECT_EQ(list.isEmpty(), false);

  EXPECT_EQ(list.get(0), 1);

  EXPECT_EQ(list.contains(1), 5);

  list.set(4, 9);
  EXPECT_EQ(list.get(4), 9);

  int value = list.remove(0);
  EXPECT_EQ(value, 1);
  
  EXPECT_EQ(list.removeAll(1), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
