#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  extern std::string TraversalResult;
  std::string str1 = "ABDCEGF";
  std::string str2 = "BDAGECF";
  Node *root = build(str1, str2);
  preorder_traversal(root);
  EXPECT_EQ(TraversalResult, "ABDCEGF");
  inorder_traversal(root);
  EXPECT_EQ(TraversalResult, "BDAGECF");
  postorder_traversal(root);
  EXPECT_EQ(TraversalResult, "DBGEFCA");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
