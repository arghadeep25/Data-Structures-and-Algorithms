/************************************
 * @file singly_linked_list.hpp
 * @details Singly Linked List Header
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once

#include <iostream>
#include <unordered_map>

#include "utils/colors.hpp"

namespace dataStructure::singlyLinkedList {
/**
 * @brief Singly Linked List
 * @details Class for Singly Linked List
 * @tparam Data Data Type e.g int, float
 */
template <typename Data> class Node {
public:
  Data data;
  Node *next;

public:
  Node() : data(0), next(nullptr) {}
  explicit Node(Data new_data) : data(new_data), next(nullptr) {}
  Node(Data new_data, Node *new_node) : data(new_data), next(new_node) {}

public:
  /**
   * @brief Print Linked List
   * @details Function to print the linked list
   * @param node Node
   */
  static void printList(Node *node) {
    std::cout << YELLOW << "Elements in Singly Linked List: ";
    while (node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << RESET << std::endl;
  }

public:
  /**
   * @brief Insert Element at Front
   * @details Function to insert an element at the front of the linked list
   * @param head_ref Head of the linked list
   * @param new_data Data
   */
  static void insertAtFront(Node **head_ref, Data new_data) {
    std::cout << GREEN << "Inserting Node at Front" << RESET << std::endl;
    // Allocating New Node
    Node *new_node = new Node(new_data, *head_ref);
    // Moving the head to point to the new node
    *head_ref = new_node;
  }

public:
  /**
   * @brief Insert Element at Last
   * @details Function to insert an element at the last of the linked list
   * @param head_ref Head of the linked list
   * @param new_data Data
   */
  static void insertAtLast(Node **head_ref, Data new_data) {
    std::cout << GREEN << "Inserting Node at End" << RESET << std::endl;
    // Allocating New Node with data and as it will be the last node
    // so it will be nullptr
    Node *new_node = new Node(new_data);
    // Allocating Last Node
    Node *last_node = *head_ref;
    // If linked list is empty, then last node is the head
    if (*head_ref == nullptr)
      *head_ref = new_node;
    // Traverse till the last node
    while (last_node->next != nullptr)
      last_node = last_node->next;
    // Changing the next of last node
    last_node->next = new_node;
  }

public:
  /**
   * @brief Insert element anywhere
   * @details Function to insert an element anywhere at the linked list
   * @param prev_node Previous Node of the linked list
   * @param new_data Data
   */
  static void insertAnywhere(Node *prev_node, Data new_data) {
    std::cout << GREEN << "Inserting Node at Desired Position" << RESET
              << std::endl;
    if (prev_node == nullptr) {
      std::cout << BOLD << RED << "WARNING!! Previous Node can't be Nullptr"
                << RESET << std::endl;
      return;
    }
    // Allocating new node with data and assigning next of new node as
    // next of previous node
    Node *new_node = new Node(new_data, prev_node->next);
    // Assigning next of previous node as new node
    prev_node->next = new_node;
  }

public:
  /**
   * @brief Count number of nodes
   * @details Function to count the number of nodes in the linked list
   * @param node Node
   */
  static void getNodesCount(Node *node) {
    int count = 0;
    Node *current = node;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    std::cout << YELLOW << "Number of Nodes in the Linked List: " << count
              << RESET << std::endl;
  }

public:
  /**
   * @brief Find duplicate elements
   * @details Function to find duplicate elements in the linked list using hash
   *          table Time Complexity: O(n)
   * @param node Node
   */
  static void findDuplicate(Node *node) {
    if (node == nullptr)
      std::cout << CYAN << "No duplicate elements" << RESET << std::endl;
    // Creating hash table
    std::unordered_map<Data, int> hash_table;
    // Traversing through the rest of the nodes
    while (node != nullptr) {
      hash_table[node->data]++;
      node = node->next;
    }
    for (const auto &elem : hash_table)
      if (elem.second > 1)
        std::cout << MAGENTA << "Element " << elem.first << " is repeated "
                  << elem.second << " times" << RESET << std::endl;
  }

public:
  /**
   * @brief Loop Detection
   * @details Function to detect a loop in the linked list
   * @param node Node
   */
  static void detectLoop(Node *node) {
    // Assigning slow and fast pointer
    Node *slow_pointer = node;
    Node *fast_pointer = node;
    // Slow pointer and fast pointer traversal
    while (slow_pointer && fast_pointer && fast_pointer->next) {
      slow_pointer = slow_pointer->next;
      fast_pointer = fast_pointer->next->next;
      // Checking if the slow point and fast pointer meet or not
      if (slow_pointer == fast_pointer)
        std::cout << BLUE << "Loop Detected" << RESET << std::endl;
    }
  }

public:
  /**
   * @brief Delete first node
   * @details Function to delete first node of the linked list
   * @param head_ref head reference of the linked list
   */
  static void deleteFirstNode(Node **head_ref) {
    std::cout << RED << "Deleting First Node" << RESET << std::endl;
    // Storing the head
    Node *temp = *head_ref;
    // Checking if the linked list is empty or not
    if (*head_ref == nullptr) {
      std::cout << BOLD << RED << "WARNING!! Linked List Already Empty!!"
                << std::endl;
      return;
    }
    // Assigning head to the next node
    *head_ref = temp->next;
    // Deleting the element
    delete temp;
  }

public:
  /**
   * @brief Delete Last Node
   * @details Function to delete last node of the linked list
   * @param head_ref  head reference
   */
  static void deleteLastNode(Node **head_ref) {
    std::cout << RED << "Deleting the Last Node" << std::endl;
    Node *temp = *head_ref;
    // Checking if the linked list is empty or not
    if (*head_ref == nullptr) {
      std::cout << BOLD << RED << "Linked List Already Empty" << std::endl;
      return;
    }
    // Traversing till end of the linked list
    while (temp->next->next != nullptr)
      temp = temp->next;
    // Assigning the second last node to nullptr
    temp->next = nullptr;
  }

public:
  /**
   * @brief Delete based on key
   * @details Function to delete a node based on the key element
   * @todo Need to implement 
   * @param head_ref head reference
   * @param key value of the key
   */
  static void deleteBasedOnKey(Node **head_ref, Data key) {}
};
} // namespace dataStructure::singlyLinkedList