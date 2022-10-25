/************************************
 * @file stack.hpp
 * @details Stack
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#include <iostream>
#include <utils/message.hpp>

namespace dataStructure::stack {
/**
 * @details Linked List Implementation of Stack
 * @tparam DataType
 */
template <typename DataType> class stack {
private:
  class Node {
  public:
    int data{};
    Node *next;

  public:
    // Constructors
    Node() = default;
    explicit Node(DataType data_) : data(data_), next(nullptr) {}

    // Destructor
    ~Node() = default;
  };

public:
  /**
   * @details Function to insert elements in stack
   * @param data
   */
  void push(DataType data) {
    Node *new_node = new Node(data);
    if (isFull()) {
      WARNING("Stack Overflow!!");
      exit(1);
    }
    if (data > max_)
      max_ = data;
    new_node->next = TOP;
    TOP = new_node;
  }

public:
  /**
   * @details Function to delete elements in stack
   * @return deleted element
   */
  DataType pop() {
    if (isEmpty()) {
      WARNING("Stack Underflow!!");
      exit(1);
    }
    Node *temp = TOP;
    DataType data = temp->data;
    TOP = temp->next;
    delete (temp);
    return data;
  }

public:
  /**
   * @details Function to get size of stack
   * @return size
   */
  size_t size() {
    size_t size_ = 0;
    if (isEmpty()) {
      return size_;
    }
    Node *temp = TOP;
    while (temp) {
      temp = temp->next;
      ++size_;
    }
    return size_;
  }

public:
  /**
   * @details Function to print elements in stack
   */
  void print() {
    if (isEmpty()) {
      WARNING("Stack Underflow!!");
      exit(1);
    }
    Node *temp = TOP;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }

public:
  /**
   * @details Function to check whether the stack is empty or not
   * @return  true or false
   */
  bool isEmpty() {
    if (TOP == nullptr)
      return true;
    else
      return false;
  }

public:
  /**
   * @details Function to check whether the stack is full or not
   * @return  true or false
   */
  bool isFull() {
    Node *temp = new Node;
    if (temp == nullptr)
      return true;
    else
      return false;
  }

public:
  /**
   * @details Function to get first element of the stack
   * @return  first element
   */
  DataType top() {
    if (isEmpty()) {
      WARNING("Stack Underflow!!");
      exit(1);
    }
    return TOP->data;
  }

public:
  /**
   * @details Function to get max element in the stack
   * @return  maximum value of the element
   */
  DataType max() { return max_; }

private:
  Node *TOP = nullptr;
  DataType max_ = static_cast<DataType>(INT8_MIN);
};
} // namespace dataStructure::stack