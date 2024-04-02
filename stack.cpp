#include "stack.h"
#include <iostream>

Stack::Stack() {
  items = std::vector<int>();
}

bool Stack::empty() const {
  return items.empty();
}

void Stack::push(int item) {
  items.push_back(item);
}

int Stack::pop() {
  int item = items.back();
  items.pop_back();
  return item;
}

int Stack::peek_top() const {
  return items.back();
}

double Stack::average() const {
  double sum = 0;
  for (int item : items) {
    sum += item;
  }
  return sum / items.size();
}

void Stack::pretty_print() const {
  std::cout << "[";
  for (int item : items) {
    std::cout << item << ",";
  }
  std::cout << "] <- top" << std::endl;
}