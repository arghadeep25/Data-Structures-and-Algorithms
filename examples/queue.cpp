/************************************
 * @file deque.cpp
 * @details Queue Example
 * @author Arghadeep Mazumder
 * @version 1.0.0
 * @copyright -
 ************************************/

#include <iostream>
#include <queue/queue.hpp>

int main(int argc, char **argv) {
  using Queue = dataStructure::queue::queue<int>;
  Queue queue;
  queue.enqueue(5);
  queue.enqueue(4);
  queue.enqueue(11);
  queue.enqueue(3);
  queue.enqueue(6);
  queue.print();
  MESSAGE("Size: ", queue.size());
  MESSAGE("Front: ", queue.front());
  MESSAGE("Rear: ", queue.rear());
  queue.dequue();
  queue.dequue();
  queue.print();
  MESSAGE("Size: ", queue.size());
  MESSAGE("Front: ", queue.front());
  MESSAGE("Rear: ", queue.rear());
}