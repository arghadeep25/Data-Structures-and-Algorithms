#include <iostream>
#include <stack/stack.hpp>

int main(int argc, char **argv) {
  using Stack = dataStructure::stack::stack<int>;

  Stack stack;
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(9);
  stack.push(1);
  stack.push(11);
  stack.print();
  MESSAGE("Size: ", stack.size());
  MESSAGE("Top: ", stack.top());
  MESSAGE("Max: ", stack.max());
  stack.pop();
  stack.pop();
  stack.pop();
  stack.print();
  MESSAGE("Size: ", stack.size());
  MESSAGE("Top: ", stack.top());
}