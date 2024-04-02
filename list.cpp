#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

template<typename Item_Type>
List<Item_Type>::List() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

template<typename Item_Type>
List<Item_Type>::~List() {
  while (head != nullptr) {
    pop_front();
  }
}

template<typename Item_Type>
void List<Item_Type>::push_front(const Item_Type& item) {
  bool is_empty = empty();
  if (is_empty) {
    head = new Node<Item_Type>(item, nullptr);
    tail = head;
  } else {
    // List has one or more nodes
    Node<Item_Type>* old_head = head;
    head = new Node<Item_Type>(item, old_head);
    // Tail need not be changed
  }
  // Increment the number of items
  num_items++;
}

template<typename Item_Type>
void List<Item_Type>::push_back(const Item_Type& item) {
  bool is_empty = empty();
  if (is_empty) {
    head = new Node<Item_Type>(item, nullptr);
    tail = head;
  }
  if (!is_empty) {
    Node<Item_Type>* old_tail = tail;
    tail = new Node<Item_Type>(item, nullptr);
    old_tail->setNext(tail);
  }
  // Increment the number of items
  num_items++;
}

template<typename Item_Type>
void List<Item_Type>::pop_front() {
  if (empty()) {
    throw std::runtime_error("pop_front: Attempt to pop from an empty list");
  }
  if (num_items == 1) {
    delete head;
    head = nullptr;
    tail = nullptr;
  } else {
    // List has two or more nodes
    Node<Item_Type>* new_head = head->getNext();
    delete head;
    head = new_head;
  }
  // Decrement the number of items
  num_items--;
}

template<typename Item_Type>
void List<Item_Type>::pop_back() {
  if (empty()) {
    throw std::runtime_error("pop_back: Attempt to pop from an empty list");
  }
  if (num_items == 1) {
    delete head;
    head = nullptr;
    tail = nullptr;
  } else {
    Node<Item_Type>* old_tail = tail;
    Node<Item_Type>* node_before_tail = head;
    // Get a pointer to the node before the tail
    while (node_before_tail->getNext() != old_tail) {
      node_before_tail = node_before_tail->getNext();
    }
    tail = node_before_tail;
    tail->setNext(nullptr);
    delete old_tail;
  }
  // Decrement the number of items
  num_items--;
}

template<typename Item_Type>
Item_Type& List<Item_Type>::front() {
  if (empty()) {
    throw std::runtime_error("front: Attempt to access the front of an empty list");
  }
  return head->getData();
}

template<typename Item_Type>
Item_Type& List<Item_Type>::back() {
  if (empty()) {
    throw std::runtime_error("back: Attempt to access the back of an empty list");
  }
  return tail->getData();
}

template<typename Item_Type>
bool List<Item_Type>::empty() const {
  return num_items == 0;
}

template<typename Item_Type>
void List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
  if (index == 0) {
    push_front(item);
  } else if (index >= num_items) {
    push_back(item);
  } else {
    // Insert in the middle
    Node<Item_Type>* node_before_insert = head;
    for (std::size_t i = 0; i < index - 1; i++) {
      node_before_insert = node_before_insert->getNext();
    }
    Node<Item_Type>* node_after_insert = node_before_insert->getNext();
    Node<Item_Type>* new_node = new Node<Item_Type>(item, node_after_insert);
    node_before_insert->setNext(new_node);
    // Increment the number of items
    num_items++;
  }
}

template<typename Item_Type>
bool List<Item_Type>::remove(std::size_t index) {
  if (index >= num_items) {
    return false;
  }
  if (index == 0) {
    pop_front();
  } else if (index == num_items - 1) {
    pop_back();
  } else {
    // Remove from the middle
    Node<Item_Type>* node_before_remove = head;
    for (std::size_t i = 0; i < index - 1; i++) {
      node_before_remove = node_before_remove->getNext();
    }
    Node<Item_Type>* node_to_remove = node_before_remove->getNext();
    Node<Item_Type>* node_after_remove = node_to_remove->getNext();
    node_before_remove->setNext(node_after_remove);
    delete node_to_remove;
    // Decrement the number of items
    num_items--;
  }
  return true;
}

template<typename Item_Type>
std::size_t List<Item_Type>::find(const Item_Type& item) {
  Node<Item_Type>* current = head;
  std::size_t index = 0;
  while (current != nullptr) {
    if (current->getData() == item) {
      return index;
    }
    current = current->getNext();
    index++;
  }
  return num_items;
}

template<typename Item_Type>
void List<Item_Type>::pretty_print() {
  Node<Item_Type>* current = head;
  std::cout << "[";
  while (current != nullptr) {
    std::cout << current->getData() << ",";
    current = current->getNext();
  }
  std::cout << "]";
}

template class List<int>;