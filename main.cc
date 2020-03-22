#include "gtest/gtest.h"
#include "LinkList.h"

TEST(Suite1, Test1) {
  LinkList<int> list;
  const int N = 5;

  for (int i = 0; i < N; i++) {
    list.insert(i + 1);
  }

  int n = N;
  for (int d : list) {
    EXPECT_EQ(d, n);
    n--;
  }
  EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
