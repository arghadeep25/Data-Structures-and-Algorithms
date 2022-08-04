//============================================================================
// Name        : binary_tree.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description : Binary Tree
//============================================================================
#pragma once

#include "utils/message.hpp"
#include <iostream>
#include <vector>

namespace dataStructure::binary_tree {
/**
 * @brief Binary Tree Implementation
 * @tparam DataType
 * @details
 *
 */
template <typename DataType> class BinaryTree {
public:
  struct Node {
    DataType data;
    Node *left = nullptr;
    Node *right = nullptr;
  };

public:
  BinaryTree() = default;

public:
  ~BinaryTree() = default;

public:
  /**
   * @brief Function to insert elements in a tree
   * @param data
   * @details
   */
  void insert(DataType data) {
    if (root == nullptr) {
      root = new Node();
      root->data = data;
    } else
      insert(root, data);
  }

private:
  /**
   * @brief Function to insert elements in a tree starting from root
   * @param leaf
   * @param data
   * @details
   */
  void insert(Node *leaf, DataType &data) {
    if (data < leaf->data) {
      if (leaf->left != nullptr)
        insert(leaf->left, data);
      else {
        leaf->left = new Node();
        leaf->left->data = data;
      }
    } else if (data >= leaf->data) {
      if (leaf->right != nullptr)
        insert(leaf->right, data);
      else {
        leaf->right = new Node();
        leaf->right->data = data;
      }
    }
  }

public:
  /**
   * @brief Generating binary tree from vector
   * @param tree
   * @param data
   * @details
   */
  void createTree(BinaryTree *tree, std::vector<DataType> &data) {
    if (data.empty())
      exit(-1);
    for (const auto &elem : data)
      tree->insert(elem);
  }

public:
  /**
   * @brief Generating Balanced Tree from vector
   * @tparam Iterator
   * @param data
   * @details
   */
  template <typename Iterator>
  static void createBalancedTree(std::vector<DataType> &data) {
    if (data.empty())
      return;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type
        difference_type;
    Iterator first = data.begin();
    Iterator last = data.end();
  }

public:
  /**
   * @brief Preorder Traversal of Tree
   * @details Algorithm Preorder(tree)
   *           1. Visit the root.
   *           2. Traverse the left subtree
   *           3. Traverse the right subtree
   */
  void preOrderTraverse() {
    preOrderTraverse(root);
    ENDLINE;
  }

private:
  /**
   * @brief Preorder Traversal of Tree
   * @param leaf
   * @details
   */
  void preOrderTraverse(Node *leaf) {
    if (leaf != nullptr) {
      PRINT_DATA(leaf->data);
      traverse(leaf->left);
      traverse(leaf->right);
    }
  }

public:
  /**
   * @brief Postorder Traversal of Tree
   * @details Algorithm Postorder
   *           1. Traverse the left subtree
   *           2. Traverse the right subtree
   *           3. Visit the root.
   */
  void postOrderTraverse() {
    postOrderTraverse(root);
    ENDLINE;
  }

private:
  /**
   * @brief Postorder Traversal of Tree
   * @param leaf
   * @details
   */
  void postOrderTraverse(Node *leaf) {
    if (leaf != nullptr) {
      traverse(leaf->left);
      traverse(leaf->right);
      PRINT_DATA(leaf->data);
    }
  }

public:
  /**
   * @brief Inorder Traversal of Tree
   * @details Algorithm Inorder
   *           1. Traverse the left subtree
   *           2. Visit the root.
   *           3. Traverse the right subtree
   */
  void inOrderTraverse() {
    traverse(root);
    ENDLINE;
  }

private:
  /**
   * @brief Inorder Traversal of Tree
   * @param leaf
   * @details
   */
  void traverse(Node *leaf) {
    if (leaf != nullptr) {
      traverse(leaf->left);
      PRINT_DATA(leaf->data);
      traverse(leaf->right);
    }
  }

public:
  /**
   * @brief Function to find depth or height of tree
   * @details
   */
  void height() {
    if (root == nullptr) {
      STATUS("Tree is Empty!!", RED);
      return;
    }
    int depth = height(root);
    MESSAGE("Tree Depth: ", depth);
  }

private:
  int height(Node *leaf) {
    if (leaf == nullptr)
      return -1;
    else {
      int lheight = height(leaf->left);
      int rheight = height(leaf->right);
      return std::max(lheight, rheight) + 1;
    }
  }

public:
  /**
   * @brief Count the Number of nodes in a tree
   */
  void countNodes() {
    if (root == nullptr)
      return;
    int nodes = countNodes(root);
    MESSAGE("Number of Nodes: ", nodes);

  }
private:
  /**
   * @brief
   * @param leaf
   * @return number of nodes
   */
  int countNodes(Node *leaf){
    if(leaf == nullptr)
      return 0;
    return 1 + (countNodes(leaf->left) + countNodes(leaf->right));
  }

public:
  // Function to check the type of the tree
  // #TODO check the tree is full or complete or perfect  or skewed or
  // degenerate binary tree
  static void checkTreeType() {}

public:
  // Function to find the diameter of the tree
  // Definition: The number of nodes on the longest path between two end nodes.
  // #TODO
  static void treeDiameter() {}

public:
  // Function to remove
  static void remove() {}

private:
  Node *root;
};
} // namespace dataStructure::binary_tree