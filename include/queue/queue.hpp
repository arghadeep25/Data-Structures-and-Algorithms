/************************************
 * @file Queue.hpp
 * @details Queue
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/
#include <iostream>
#include <utils/message.hpp>

namespace dataStructure::queue {
/**
 * @details Linked list implementation of Queue
 * @tparam DataType
 */
template <typename DataType> class queue {
private:
  class Node {
  public:
    DataType data;
    Node *next;

    // Constructors
  public:
    Node() = default;
    Node(DataType data_) : data(data_), next(nullptr) {}

    // Destructor
    ~Node() = default;
  };

private:
  Node *front_ = nullptr;
  Node *rear_ = nullptr;

  // Constructor
public:
  queue() = default;

  // Destructor
public:
  ~queue() = default;

  /**
   * @details Function to check whether the queue is empty or not
   * @return  true or false
   */
public:
  bool isEmpty() {
    if (front_ == nullptr && rear_ == nullptr)
      return true;
    else
      return false;
  }

  /**
   * @details Function to check whether the queue is full or not
   * @return  true or false
   */
public:
  bool isFull(){
    Node *temp_node = new Node;
    if(temp_node == nullptr)
      return true;
    else{
      delete(temp_node);
      return false;
    }
  }

  /**
   * @details Function to insert elements in the queue
   * @param data
   */
public:
  void enqueue(DataType data) {
    if (isFull()) {
      WARNING("Queue Overflow!!");
      exit(1);
    }
    Node *new_node = new Node(data);
    if (front_ == nullptr) {
      rear_ = new_node;
      front_ = new_node;
    } else {
      rear_->next = new_node;
      rear_ = new_node;
    }
  }

  /**
   * @details Function to delete elements in the queue
   * @param data
   */
public:
  DataType dequue() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    DataType temp_val_ = front_->data;
    if (front_ == rear_) {
      delete (front_);
      front_ = rear_ = nullptr;
    } else {
      Node *temp = front_;
      front_ = front_->next;
      delete (temp);
    }
    return temp_val_;
  }

  /**
   * @details Function to get the front element of the queue
   * @return value
   */
public:
  DataType front() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    return front_->data;
  }

  /**
   * @details Function to get the end element of the queue
   * @return value
   */
public:
  DataType rear() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    return rear_->data;
  }

  /**
   * @details Function to get the size of the queue
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
    return size_;
  }

  /**
   * @details Function to print the elements in the queue
   */
public:
  void print() {
    if (isEmpty()) {
      WARNING("Queue Underflow!!");
      exit(1);
    }
    Node *temp = front_;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
    delete(temp);
  }
};
} // namespace dataStructure::queue