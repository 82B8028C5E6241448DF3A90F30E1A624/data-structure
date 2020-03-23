#include <iostream>
#include "Bracket.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  bool result1 = bracket("{ ( 8 + 2 ) * ( 3 + 5 ) * 2 }");
  EXPECT_EQ(result1, true);
  bool result2 = bracket("{ ( [8 + 2] ) * ( 3 + 5 ) * 2 }");
  EXPECT_EQ(result2, true);
  bool result3 = bracket("{ ( [8 + 2 ) * ( 3 + 5 ) * 2 }");
  EXPECT_EQ(result3, false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
