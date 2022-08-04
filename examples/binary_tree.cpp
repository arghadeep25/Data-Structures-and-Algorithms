#include "binary_tree/binary_tree.hpp"
#include "utils/rand_vec.hpp"
#include <iostream>

int main(int argc, char **argv) {
  using BinaryTree = dataStructure::binary_tree::BinaryTree<int>;
  // Generating vector of random integers
  std::vector<int> data =
      dataStructure::utils::generateRandomVector(15, 0, 100);
  // Declaring object
  auto *tree = new BinaryTree();
  // Generating tree from the vector
  tree->createTree(tree, data);
  // Inorder traversal
  MESSAGE("Inorder Traversal");
  tree->inOrderTraverse();
  // Preorder traversal
  MESSAGE("Preorder Traversal");
  tree->preOrderTraverse();
  // Postorder traversal
  MESSAGE("Postorder Traversal");
  tree->postOrderTraverse();
}