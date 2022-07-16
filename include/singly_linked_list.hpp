//============================================================================
// Name        : singly_linked_list.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#pragma once

#include <iostream>
#include <unordered_map>

template <typename Data> class Node {
public:
  Data data;
  Node *next;

public:
  Node() : data(0), next(nullptr) {}
  explicit Node(Data new_data) : data(new_data), next(nullptr) {}
  Node(Data new_data, Node *new_node) : data(new_data), next(new_node) {}

public:
  // Function to print the elements in the linked list
  static void printList(Node *node) {
    std::cout << "Elements in the Linked List: ";
    while (node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << std::endl;
  }

public:
  // Insert a new node at the beginning of the linked list
  static void insertAtFront(Node **head_ref, Data new_data) {
    std::cout << "Inserting a new node at the front" << std::endl;
    // Allocating New Node
    Node *new_node = new Node(new_data, *head_ref);
    // Moving the head to point to the new node
    *head_ref = new_node;
  }

public:
  // Function to insert a new node at the end of the linked list
  static void insertAtLast(Node **head_ref, Data new_data) {
    std::cout << "Inserting a new node at the end" << std::endl;
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
  static void insertAnywhere(Node *prev_node, Data new_data) {
    std::cout << "Inserting a new node at the desired position" << std::endl;
    if (prev_node == nullptr) {
      std::cout << "Previous Node cannot be Nullptr" << std::endl;
      return;
    }
    // Allocating new node with data and assigning next of new node as
    // next of previous node
    Node *new_node = new Node(new_data, prev_node->next);
    // Assigning next of previous node as new node
    prev_node->next = new_node;
  }

public:
  // Get number of nodes in a linked list
  static void getNodesCount(Node *node) {
    int count = 0;
    Node *current = node;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    std::cout << "Number of Nodes in the Linked List: " << count << std::endl;
  }

public:
  // Find if there is any duplicate element in the linked list using hash table
  // Time Complexity O(n)
  static void findDuplicate(Node *node) {
    if (node == nullptr)
      std::cout << "No duplicate elements" << std::endl;
    // Creating hash table
    std::unordered_map<Data, int> hash_table;
    // Traversing through the rest of the nodes
    while (node != nullptr) {
      hash_table[node->data]++;
      node = node->next;
    }
    for (const auto &elem : hash_table)
      if (elem.second > 1)
        std::cout << "Element " << elem.first << " is repeated " << elem.second
                  << " times" << std::endl;
  }

public:
  // Function to detect a loop in a linked list
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
        std::cout << "Loop Detected" << std::endl;
    }
  }

public:
  // Function to delete the first node of the linked list
  static void deleteFirstNode(Node **head_ref) {
    std::cout << "Deleting First Node" << std::endl;
    // Storing the head
    Node *temp = *head_ref;
    // Checking if the linked list is empty or not
    if (*head_ref == nullptr) {
      std::cout << "Linked List Already Empty!!" << std::endl;
      return;
    }
    // Assigning head to the next node
    *head_ref = temp->next;
    // Deleting the element
    delete temp;
  }

public:
  // Function to delete the last node from the linked list
  static void deleteLastNode(Node **head_ref) {
    std::cout << "Deleting the Last Node" << std::endl;
    Node *temp = *head_ref;
    // Checking if the linked list is empty or not
    if(*head_ref == nullptr){
      std::cout << "Linked List Already Empty" << std::endl;
      return;
    }
    // Traversing till end of the linked list
    while(temp->next->next != nullptr){
      temp = temp->next;
    }
    // Assigning the second last node to nullptr
    temp->next = nullptr;
  }

public:
  // Function to delete a node based on key
  static void deleteBasedOnKey(Node **head_ref, Data key) {}
};