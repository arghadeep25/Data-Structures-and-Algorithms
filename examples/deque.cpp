/************************************
* @file deque.cpp
* @details Double Ended Queue Example
* @author Arghadeep Mazumder
* @version 1.0.0
* @copyright -
************************************/

#include <iostream>
#include <queue/deque.hpp>

int main(int argc, char ** argv){
  using Deque = dataStructure::queue::deque<int>;
  Deque deque;
  deque.enqueueFront(1);
  deque.enqueueFront(2);
  deque.enqueueRear(4);
  deque.enqueueRear(3);
  deque.enqueueRear(5);
  deque.enqueueFront(6);
  deque.print();
  MESSAGE("Size: ",deque.size());
  deque.front();
  deque.rear();
  deque.dequeueRear();
  deque.print();
  deque.dequeueFront();
  deque.print();
  MESSAGE("Size: ",deque.size());
  deque.front();
  deque.rear();

}