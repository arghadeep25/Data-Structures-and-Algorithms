/************************************
* @file deque.cpp
* @details Double Ended Queue Example
* @author Arghadeep Mazumder
* @version 1.0.0
* @copyright -
************************************/

#include <iostream>
#include <queue/circular_queue.hpp>

int main(int argc, char ** argv){
  using CircularQueue = dataStructure::queue::circularQueue<int>;
  CircularQueue circqueue;
  circqueue.enqueue(3);
  circqueue.enqueue(4);
  circqueue.enqueue(6);
  circqueue.print();
  circqueue.dequeue();
  circqueue.dequeue();
  circqueue.print();
}