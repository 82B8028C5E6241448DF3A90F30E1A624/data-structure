#include <iostream>
#include <string>

struct Node {
  char data;
  struct Node *left_node;
  struct Node *right_node;
};
std::string TraversalResult;

Node *build(std::string preorder, std::string inorder) {
  int size = preorder.length();
  if (size == 0) return nullptr;

  Node *node = new Node();
  node->data = preorder[0];

  int left_size = inorder.find(preorder[0]);
  int right_size = size - left_size - 1;
  std::string preorder_left = preorder.substr(1, left_size);
  std::string inorder_left = inorder.substr(0, left_size);
  std::string preorder_right = preorder.substr(left_size + 1, right_size);
  std::string inorder_right = inorder.substr(left_size + 1, right_size);

  node->left_node = build(preorder_left, inorder_left);
  node->right_node = build(preorder_right, inorder_right);

  return node;
}

int preorder_trav(Node *node) {
  if (node == nullptr) return 0;
  TraversalResult += node->data;
  preorder_trav(node->left_node);
  preorder_trav(node->right_node);
  return 0;
}

std::string preorder_traversal(Node *node) {
  TraversalResult = "";
  preorder_trav(node);
  return TraversalResult;
}

int inorder_trav(Node *node) {
  if (node == nullptr) return 0;
  inorder_trav(node->left_node);
  TraversalResult += node->data;
  inorder_trav(node->right_node);
  return 0;
}

std::string inorder_traversal(Node *node) {
  TraversalResult = "";
  inorder_trav(node);
  return TraversalResult;
}

int postorder_trav(Node *node) {
  if (node == nullptr) return 0;
  postorder_trav(node->left_node);
  postorder_trav(node->right_node);
  TraversalResult += node->data;
  return 0;
}

std::string postorder_traversal(Node *node) {
  TraversalResult = "";
  postorder_trav(node);
  return TraversalResult;
}

