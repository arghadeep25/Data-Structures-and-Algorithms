#include <iostream>
#include <gtest/gtest.h>
#include "singly_linked_list.hpp"

int main(int argc, char **argv) {
  using Node = Node<int>;
  // Creating the last node first
  auto *third = new Node(3);
  auto *second = new Node(1, third);
  auto *head = new Node(1, second);

    Node::printList(head);
    Node::getNodesCount(head);
    Node::insertAtFront(&head, 1);
    Node::printList(head);
    Node::insertAtLast(&head,9);
    Node::printList(head);
    Node::insertAnywhere(head->next, 9);
    Node::printList(head);
    Node::getNodesCount(head);
    Node::findDuplicate(head);
    Node::detectLoop(head);
    Node::deleteFirstNode(&head);
    Node::printList(head);
    Node::deleteLastNode(&head);
    Node::printList(head);
}