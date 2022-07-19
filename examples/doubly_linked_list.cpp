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
  //Head
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);

  third->next = nullptr;
  second->next = third;
  head->next = second;

  second->prev = head;
  third->prev = second;

  Node::printAllElements(head);
  Node::insertAtFront(&head, 4);
  Node::printAllElements(head);
  Node::insertAtBack(&head, 7);
  Node::printAllElements(head);
  Node::insertAnywhere(third->next, 8);
  Node::printAllElements(head);
}