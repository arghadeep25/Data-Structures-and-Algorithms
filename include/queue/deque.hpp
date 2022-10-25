/************************************
 * @file deque.hpp
 * @details Doubly Ended Queue
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/
#include <iostream>
#include <utils/message.hpp>

namespace dataStructure::queue {
/**
 * @details Linked list implementation of Double Ended Queue (Deque)
 * @tparam DataType
 */
template <typename DataType> class deque {
private:
  /**
   * @details Node for doubly linked list
   */
  class Node {
  public:
    DataType data;
    Node *next;
    Node *prev;

    // Default constructor
  public:
    Node() = default;
    explicit Node(DataType data_) : data(data_), next(nullptr), prev(nullptr) {}

    // Default destructor
  public:
    ~Node() = default;
  };

private:
  Node *front_ = nullptr;
  Node *rear_ = nullptr;

public:
  deque() = default;
  ~deque() = default;

public:
  /**
   * @details Function to check whether the deque is empty or not
   * @return  true or false
   */
  bool isEmpty() {
    if (rear_ == nullptr)
      return true;
    else
      return false;
  }

  /**
   * @details Function to check whether the deque is full or not
   * @return  true or false
   */
public:
  bool isFull() {
    Node *temp_node = new Node;
    if (temp_node == nullptr)
      return true;
    else {
      delete(temp_node);
      return false;
    }
  }

  /**
   * @details Function to print the elements in the deque
   */
public:
  void print() {
    if (isEmpty()) {
      WARNING("Empty Underflow!!");
      return;
    }
    std::cout << "Elements: ";
    Node *temp = front_;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
    delete(temp);
  }

  /**
   * @details Function to insert elements at the end of the deque
   * @param data
   */
public:
  void enqueueRear(DataType data) {
    if (isFull()) {
      WARNING("Queue Overflow!!");
      exit(1);
    }
    Node *new_node = new Node(data);
    if (rear_ == nullptr) {
      front_ = rear_ = new_node;
    } else {
      new_node->prev = rear_;
      rear_->next = new_node;
    }
    rear_ = new_node;
  }

  /**
   * @details Function to insert elements at the front of the deque
   * @param data
   */
public:
  void enqueueFront(DataType data) {
    if (isFull()) {
      WARNING("Queue Overflow!!");
      exit(1);
    }
    Node *new_node = new Node(data);
    if (front_ == nullptr)
      rear_ = front_ = new_node;
    else {
      new_node->next = front_;
      front_->prev = new_node;
    }
    front_ = new_node;
  }

  /**
   * @details Function to delete element from the beginning of the deque
   */
public:
  DataType dequeueFront() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    Node *temp = front_;
    DataType data = temp->data;
    front_ = front_->next;
    if (front_ == nullptr)
      rear_ = nullptr;
    else
      front_->prev = nullptr;
    delete (temp);
    return data;
  }

  /**
   * @details Function to delete element from the end of the deque
   */
public:
  DataType dequeueRear() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    Node *temp = rear_;
    DataType data = temp->data;
    rear_ = rear_->prev;
    if (rear_ == nullptr)
      front_ = nullptr;
    else
      rear_->next = nullptr;
    delete (temp);
    return data;
  }

  /**
   * @details Function to get the front element of the deque
   * @return value
   */
public:
  DataType front() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    MESSAGE("Front: ", front_->data);
    return front_->data;
  }

  /**
   * @details Function to get the end element of the deque
   * @return value
   */
public:
  DataType rear() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    MESSAGE("Rear: ", rear_->data);
    return rear_->data;
  }

  /**
   * @details Function to get the size of the deque
   * @return size of deque
   */
public:
  size_t size() {
    size_t size_ = 0;
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      return size_;
    }
    Node *temp = front_;
    while (temp) {
      ++size_;
      temp = temp->next;
    }
    delete(temp);
    return size_;
  }
};
} // namespace dataStructure::queue
