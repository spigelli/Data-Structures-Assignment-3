#include "queue.h"
#include <iostream>
#include <fstream>

using namespace std;

template<typename Item_Type>
Queue<Item_Type>::Queue() {
  num_items = 0;
  front_of_queue = nullptr;
  back_of_queue = nullptr;
}

template<typename Item_Type>
Queue<Item_Type>::~Queue() {
  while (front_of_queue != nullptr) {
    pop();
  }
}

template<typename Item_Type>
void Queue<Item_Type>::push(const Item_Type& item) {
  bool is_empty = empty();
  if (is_empty) {
    front_of_queue = new Node<Item_Type>(item, nullptr);
    back_of_queue = front_of_queue;
  } else {
    Node<Item_Type>* old_back = back_of_queue;
    back_of_queue = new Node<Item_Type>(item, nullptr);
    old_back->setNext(back_of_queue);
  }
  num_items++;
}

template<typename Item_Type>
Item_Type Queue<Item_Type>::pop() {
  if (empty()) {
    throw std::runtime_error("pop: Attempt to pop from an empty queue");
  }
  Item_Type item = front_of_queue->getData();
  Node<Item_Type>* old_front = front_of_queue;
  front_of_queue = front_of_queue->getNext();
  delete old_front;
  num_items--;
  return item;
}

template<typename Item_Type>
Item_Type Queue<Item_Type>::front() {
  if (empty()) {
    throw std::runtime_error("front: Attempt to get front of an empty queue");
  }
  return front_of_queue->getData();
}

template<typename Item_Type>
bool Queue<Item_Type>::empty() const {
  return num_items == 0;
}

template<typename Item_Type>
std::size_t Queue<Item_Type>::size() const {
  return num_items;
}

template<typename Item_Type>
void Queue<Item_Type>::pretty_print() {
  Node<Item_Type>* current = front_of_queue;
  cout << "Back -> [";
  for (int i = num_items - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      current = current->getNext();
    }
    std::cout << current->getData();
    if (i != 0) {
      std::cout << ", ";
    }
    current = front_of_queue;
  }
  std::cout << "] <- Front" << std::endl;
}

template<typename Item_Type>
void Queue<Item_Type>::move_to_rear() {
  if (empty()) {
    throw std::runtime_error("move_to_rear: Attempt to move the front of an empty queue");
  }
  Item_Type item = pop();
  push(item);
}

template class Queue<int>;