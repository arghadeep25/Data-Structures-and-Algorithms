//============================================================================
// Name        : doubly_linked_list.hpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#pragma once

#include "utils/colors.hpp"
#include "utils/message.hpp"
#include <iostream>

namespace dataStructure::doublyLinkedList {
template <typename Data> class Node {
public:
  Data data;
  Node *prev;
  Node *next;

public:
  // Contructors
  Node() : data(0), prev(nullptr), next(nullptr) {}
  explicit Node(Data new_data) : data(new_data), prev(nullptr), next(nullptr) {}
  Node(Data new_data, Node *new_next_node)
      : data(new_data), prev(nullptr), next(new_next_node) {}
  Node(Data new_data, Node *new_prev_node, Node *new_next_node)
      : data(new_data), prev(new_prev_node), next(new_next_node) {}

public:
  // Function to print all the elements in the linked list
  static void printAllElements(Node *node) {
    std::cout << YELLOW << "Elements in the Linked List: ";
    while (node != nullptr) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << RESET << std::endl;
  }

public:
  static void getNodesCount(Node *node) {
    int count = 0;
    Node *current = node;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    PRINT("Number of Nodes in the Linked List: ", count);
  }

public:
  // Function to insert a new node at the front of the linked list
  static void insertAtFront(Node **head_ref, Data new_data) {
    STATUS("Inserting Node at Front", GREEN);
    // Allocating new node with new data, next as head_ref and prev as nullptr
    Node *new_node = new Node(new_data, *head_ref);
    // Changing prev of head node to new node
    if (*head_ref != nullptr)
      (*head_ref)->prev = new_node;
    // Moving the head to point the new node
    *head_ref = new_node;
  }

public:
  // Function to insert a new node at the end of the linked list
  static void insertAtBack(Node **head_ref, Data new_data) {
    STATUS("Inserting Node at End", GREEN);
    // Allocating a new node with new data with next and prev as nullptr
    Node *new_node = new Node(new_data);
    Node *last = *head_ref;
    // Checking if the linked list is empty or not
    if (*head_ref == nullptr) {
      // if empty, then making new node as head
      new_node->prev = nullptr;
      *head_ref = new_node;
      return;
    }
    // Traversing till the last node
    while (last->next != nullptr)
      last = last->next;
    // Changing the next of the last node
    last->next = new_node;
    // Making last node as previous of new node
    new_node->prev = last;
  }

public:
  // Inserting a new node
  static void insertAnywhere(Node *prev_node, Data data) {
    STATUS("Inserting Node at Desired Position", GREEN);
    if (prev_node == nullptr) {
      WARNING("WARNING!! Given previous node can't be NULL");
    }
    // Allocating New Node with new data and next of new node
    // as next of prev node
    Node *new_node = new Node(data, prev_node->next);
    // Making next of prev node as new node
    prev_node->next = new_node;
    // Making next of prev_node as prev of new node
    new_node->prev = prev_node;
    // Changing previous of new_node's next
    if (new_node->next != nullptr)
      new_node->next->prev = new_node;
  }

public:
  // Function to Delete First Node
  static void deleteFirstNode(Node **head_ref) {
    STATUS("Deleting First Node", RED);
    // Checking if the first node is empty or not
    if (*head_ref == nullptr) {
      WARNING("WARNING!! Linked List Already Empty");
      return;
    }
    // Temporarily storing the head_ref
    Node *temp = *head_ref;
    // Pointing the head from current position to second node
    *head_ref = (*head_ref)->next;
    // Freeing the first node
    delete temp;
    // If the current first node is not nullptr, then prev of head is nullptr
    if (head_ref != nullptr)
      (*head_ref)->prev = nullptr;
  }

public:
  // Function to delete the last node of the linked list
  static void deleteLastNode(Node **head_ref) {
    STATUS("Deleting Last Node", RED);
    // Checking if the linked list is empty or not
    if (*head_ref == nullptr) {
      WARNING("WARNING!! Linked List is Already Empty");
      return;
    }
    Node *temp = *head_ref;
    while (temp->next->next != nullptr)
      temp = temp->next;
    temp->next = nullptr;
  }

public:
  // Function to delete a node from anywhere
  // head_ref -> pointing to the head node
  // del_node -> pointing to the node to be deleted
  static void deleteFromAnywhere(Node **head_ref, Node *del_node) {
    STATUS("Deleting from Desired Position", RED);
    if (*head_ref == nullptr || del_node == nullptr) {
      WARNING("WARNING!! Node is Empty");
      return;
    }
    // If the node to be deleted is the head node
    // Pointing the head_ref to the next node
    if (*head_ref == del_node)
      *head_ref = del_node->next;
    // Change next of the node if the node is not the last node
    if (del_node->next != nullptr)
      del_node->next->prev = del_node->prev;
    // Change prev of the node if the node is not the first node
    if (del_node->prev != nullptr)
      del_node->prev->next = del_node->next;
    delete (del_node);
  }

public:
  // Function to reverse a linked list using Swapping
  static void reserveLinkedList(Node **head_ref) {
    STATUS("Reversing Linked List", YELLOW);
    if (head_ref == nullptr) {
      WARNING("Empty Linked List");
      return;
    }
    // Making a temporary node
    Node *temp = nullptr;
    // This node will traverse through the linked list
    Node *current = *head_ref;
    // The main idea here is to swap next and prev of all nodes
    while (current != nullptr) {
      // Storing the current->prev
      temp = current->prev;
      // Swapping the current->prev with current->next
      current->prev = current->next;
      // Swapping the current->next with current->prev
      current->next = temp;
      // Making the current as current->prev
      current = current->prev;
    }
    //
    if (temp != nullptr)
      // Changing the head
      *head_ref = temp->prev;
  }

public:
  // Function to merge two sorted linked list
  static Node *mergeLinkedList(Node *first, Node *second) {
    if (first == nullptr)
      return second;
    else if (second == nullptr)
      return first;

    if (first->data < second->data) {
      first->next = mergeLinkedList(first->next, second);
      first->next->prev = first;
      first->prev = nullptr;
      return first;
    } else {
      second->next = mergeLinkedList(first, second->next);
      second->next->prev = second;
      second->prev = nullptr;
      return second;
    }
  }
};
} // namespace dataStructure::doublyLinkedList