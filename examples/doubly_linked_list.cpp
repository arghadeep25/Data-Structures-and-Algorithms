//============================================================================
// Name        : doubly_linked_list.cpp
// Author      : Arghadeep Mazumder
// Version     : 1.0
// Copyright   : -
// Description :
//============================================================================
#include <iostream>
#include <linked_list/doubly_linked_list.hpp>

int main(int argc, char **argv) {
  using Node = dataStructure::doublyLinkedList::Node<int>;
  // Creating a doubly linked list:  1 <-> 2 <-> 3
  // Head
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);

  third->next = nullptr;
  second->next = third;
  head->next = second;

  second->prev = head;
  third->prev = second;

  std::cout << BOLD << GREEN << " ------- INSERTION -------" << std::endl;
  // Printing the elements in the linked list
  Node::printAllElements(head);
  // Inserting a node at front: 4 <-> 1 <-> 2 <-> 3
  Node::insertAtFront(&head, 4);
  // Printing the elements in the linked list
  Node::printAllElements(head);
  // Inserting a node at back: 4 <-> 1 <-> 2 <-> 3 <-> 7
  Node::insertAtBack(&head, 7);
  // Printing the elements in the linked list
  Node::printAllElements(head);
  // Inserting a node anywhere: 4 <-> 1 <-> 2 <-> 3 <-> 7
  Node::insertAnywhere(third->next, 8);
  // Printing the elements in the linked list
  Node::printAllElements(head);

  std::cout << BOLD << RED << " ------- DELETION -------" << std::endl;
  // Deleting First Node
  Node::deleteFirstNode(&head);
  // Printing the elements in the linked list
  Node::printAllElements(head);
}