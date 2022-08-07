/************************************
 * @file binary_tree.hpp
 * @details Binary Tree Header
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include "utils/message.hpp"
#include <iostream>
#include <queue>
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
  /**
   * @details Tree Format
   */
  struct Node {
    DataType data;
    Node *left = nullptr;
    Node *right = nullptr;
  };

  /**
   * @details Default Constructor
   */
public:
  BinaryTree() = default;

  /**
   * @details  Default Destructor
   */
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
   * @details Function to find depth or height of tree
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
  /**
   * @brief Compute height of tree recursively
   * @param leaf
   * @return height of tree
   */
  int height(Node *leaf) {
    if (leaf == nullptr)
      return -1;
    else
      return std::max(height(leaf->left), height(leaf->right)) + 1;
  }

public:
  /**
   * @details Count the Number of nodes in a tree
   */
  void countNodes() {
    if (root == nullptr)
      return;
    int nodes = countNodes(root);
    MESSAGE("Number of Nodes: ", nodes);
  }

private:
  /**
   * @param leaf
   * @return number of nodes
   */
  int countNodes(Node *leaf) {
    if (leaf == nullptr)
      return 0;
    return 1 + (countNodes(leaf->left) + countNodes(leaf->right));
  }

public:
  /**
   * @details  Function to find the diameter of the tree
   * @brief The number of nodes on the longest path between two end nodes.
   */
  void treeDiameter() {
    if (root == nullptr) {
      MESSAGE("Diameter of Tree: 0");
      return;
    }
    int dia = treeDiameter(root);
    MESSAGE("Diameter of Tree: ", dia);
  }

private:
  /**
   * @brief Counting the dia of a tree recursively
   * @details Computing the diameter by returning the max of
   *          diameter of left subtree
   *          diameter of right subtree
   *          Sum(left subtree, right subtree, 1)
   * @param leaf
   * @return diameter of the tree
   */
  int treeDiameter(Node *leaf) {
    if (leaf == nullptr)
      return 0;
    // height of left and right subtrees
    int lheight = height(leaf->left);
    int rheight = height(leaf->right);
    // get the diameter of left and right subtrees
    int ldia = treeDiameter(leaf->left);
    int rdia = treeDiameter(leaf->right);

    return std::max(lheight + rheight + 1, std::max(ldia, rdia));
  }

public:
  /**
   * @brief Binary Tree type
   * @details Function to check the type of binary tree.
   *          Empty Tree
   *          Full Binary Tree
   *          Complete Binary Tree
   *          Perfect Binary Tree
   *          Skewed Binary Tree
   */
  void checkTreeType() {
    int nodes = countNodes(root);
    if (root == nullptr) {
      STATUS("Empty Tree", RED);
      return;
    }
    if (fullBinary(root))
      STATUS("Full Binary Tree", GREEN);

    if (completeBinary(root, 0, nodes))
      STATUS("Complete Binary Tree", GREEN);

    if (perfectBinary(root, leafDepth(root)))
      STATUS("Perfect Binary Tree", GREEN);

    if (skewedBinary(root))
      STATUS("Skewed Binary Tree", GREEN);
  }

private:
  /**
   * @brief Recursive function to check if the tree is full binary
   * @details A Binary Tree is said to be a Full Binary Tree
   *          if every node has zero or two children.
   * @param leaf
   * @return
   */
  bool fullBinary(Node *leaf) {
    if (root == nullptr)
      return true;
    if (leaf->left == nullptr && leaf->right == nullptr)
      return true;
    else if (leaf->left && leaf->right)
      return (fullBinary(leaf->right) && fullBinary(leaf->right));
    return false;
  }

private:
  /**
   * @brief
   * @details A complete binary tree is a binary tree whose all
   *          levels except the last level are completely filled
   *          and all the leaves in the last level are all to the left side.
   * @param leaf
   * @param index
   * @param nodes
   * @return true or false
   */
  bool completeBinary(Node *leaf, unsigned int index, unsigned int nodes) {
    if (leaf == nullptr)
      return true;
    if (index >= nodes)
      return false;
    return (completeBinary(leaf->left, 2 * index + 1, nodes) &&
            completeBinary(leaf->right, 2 * index + 2, nodes));
  }

private:
  /**
   * @brief Function to find the depth of leftmost leaf
   * @param leaf
   * @return true or false
   */
  int leafDepth(Node *leaf) {
    int depth = 0;
    while (leaf != nullptr) {
      depth += 1;
      leaf = leaf->left;
    }
    return depth;
  }

private:
  /**
   * @brief Recursive function to check if the tree is perfect or not
   * @details A Binary tree is Perfect Binary Tree in which all internal
   *          nodes have two children and all leaves are at same level.
   * @param leaf
   * @param depth
   * @param level
   * @return true or false
   */
  bool perfectBinary(Node *leaf, unsigned int depth, unsigned int level = 0) {
    if (leaf == nullptr)
      return true;
    if (leaf->left == nullptr && leaf->right == nullptr)
      return depth == level + 1;
    if (leaf->left == nullptr || leaf->right == nullptr)
      return false;
    return perfectBinary(leaf->left, depth, level + 1) &&
           perfectBinary(leaf->right, depth, level + 1);
  }

private:
  /**
   * @details Function to check whether a binary tree is skewed
   * @param leaf
   * @return true or false
   */
  bool skewedBinary(Node *leaf) {
    if (leaf == nullptr || (leaf->left == nullptr && leaf->right == nullptr))
      return true;
    if (leaf->left && leaf->right)
      return false;
    if (leaf->left)
      return skewedBinary(leaf->left);
    return skewedBinary(leaf->right);
  }

public:
  /**
   * @details Mirroring a binary tree
   */
  void mirrorBinaryTree() {
    MESSAGE("Mirroring the Tree");
    mirrorBinaryTree(root);
  }

private:
  /**
   * @brief Mirror a binary tree
   * @details Function to mirror a binary tree
   * @param leaf
   */
  void mirrorBinaryTree(Node *leaf) {
    if (leaf == nullptr)
      return;
    std::queue<Node *> temp;
    while (!temp.empty()) {
      Node *current = temp.front();
      temp.pop();
      std::swap(current->left, current->right);
      if (current->left)
        temp.push(current->left);
      if (current->right)
        temp.push(current->right);
    }
  }

public:
  // Function to remove
  static void remove() {}

private:
  Node *root;
};
} // namespace dataStructure::binary_tree