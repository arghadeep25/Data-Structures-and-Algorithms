/************************************
 * @file circular_queue.hpp
 * @details Circular Queue
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/
#include <iostream>
#include <utils/message.hpp>

namespace dataStructure::queue {
/**
 * @details Linked list implementation of Circular Queue
 * @tparam DataType
 */
template <typename DataType> class circularQueue {
private:
  class Node {
  public:
    DataType data;
    Node *next;

    // Constructors
  public:
    Node() = default;
    explicit Node(DataType data_) : data(data_), next(nullptr) {}

    // Destructor
    ~Node() = default;
  };

private:
  Node *rear_ = nullptr;

  // Constructor
public:
  circularQueue() = default;

  // Destructor
public:
  ~circularQueue() = default;

public:
  /**
   * @details Function to insert elements in the circular queue
   * @param data
   */
  void enqueue(DataType data) {
    Node *new_node = new Node(data);
    if (isEmpty())
      new_node->next = new_node;
    else {
      new_node->next = rear_->next;
      rear_->next = new_node;
    }
    rear_ = new_node;
  }

public:
  /**
   * @details Function to delete elements in the circular queue
   * @param data
   */
  DataType dequeue() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    DataType data;
    if (rear_->next == rear_) {
      data = rear_->data;
      delete (rear_);
      rear_ = nullptr;
    } else {
      Node *temp = rear_->next;
      rear_->next = temp->next;
      data = rear_->next->data;
      delete (temp);
    }
    return data;
  }

public:
  /**
   * @details Function to print the elements in the circular queue
   */
  void print() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    Node *temp = rear_->next;
    std::cout << "Elements: ";
    do {
      std::cout << temp->data << " ";
      temp = temp->next;
    } while (temp != rear_->next);
    std::cout << std::endl;
  }

public:
  /**
   * @details Function to check whether the circular queue is empty or not
   * @return  true or false
   */
  bool isEmpty() {
    if (rear_ == nullptr)
      return true;
    else
      return false;
  }

public:
  /**
   * @details Function to get the front element of the circular queue
   * @return value
   */
  DataType front() {
    if (isEmpty())
      return NULL;
    return rear_->next->data;
  }

public:
  /**
   * @details Function to get the end element of the circular queue
   * @return value
   */
  DataType rear() {
    if (isEmpty())
      return NULL;
    return rear_->data;
  }

public:
  /**
   * @details Function to get the size of the circular queue
   * @return size of circular queue
   */
  size_t size() {
    if (isEmpty())
      return 0;
    size_t size_ = 0;
    Node *temp = rear_->next;
    do {
      temp = temp->next;
      ++size_;
    } while (temp != rear_->next);
    return size_;
  }
};
} // namespace dataStructure::queue