/************************************
 * @file singly_linked_list.hpp
 * @details Singly Linked List Example
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#pragma once
#include "linked_list/singly_linked_list.hpp"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char **argv) {
  using Node = dataStructure::singlyLinkedList::Node<int>;
  // Creating a linked list with 3 nodes
  // Creating the last node first
  auto *third = new Node(3);
  auto *second = new Node(1, third);
  // Creating the head at the last
  auto *head = new Node(1, second);
  // Printing the linked list
  Node::printList(head);
  // Counting the number of nodes in the linked list
  Node::getNodesCount(head);
  // Inserting an element at the front of the linked list
  Node::insertAtFront(&head, 1);
  // Printing the linked list
  Node::printList(head);
  // Inserting an element at the end of the linked list
  Node::insertAtLast(&head, 9);
  // Printing the linked list
  Node::printList(head);
  // Inserting an element at a desired position in the linked list
  Node::insertAnywhere(head->next, 9);
  // Printing the linked list
  Node::printList(head);
  // Counting the number of nodes in the linked list
  Node::getNodesCount(head);
  // Finding duplicate elements in the linked list
  Node::findDuplicate(head);
  // Detecting a loop in the linked list
  Node::detectLoop(head);
  // Deleting the first node of the linked list
  Node::deleteFirstNode(&head);
  // Printing the linked list
  Node::printList(head);
  // Deleting the last node of the linked list
  Node::deleteLastNode(&head);
  // Printing the linked list
  Node::printList(head);
}