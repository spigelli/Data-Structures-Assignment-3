#include "node.h"

// Constructor
template <typename Item_Type>
Node<Item_Type>::Node(Item_Type data, Node<Item_Type>* next) {
  this->data = data;
  this->next = next;
}

// Destructor
template <typename Item_Type>
Node<Item_Type>::~Node() {
  // Nothing to do here
}

// Getters and setters
template <typename Item_Type>
Item_Type& Node<Item_Type>::getData() {
  return data;
}

template <typename Item_Type>
Node<Item_Type>* Node<Item_Type>::getNext() {
  return next;
}

template <typename Item_Type>
void Node<Item_Type>::setData(Item_Type data) {
  this->data = data;
}

template <typename Item_Type>
void Node<Item_Type>::setNext(Node<Item_Type>* next) {
  this->next = next;
}

template class Node<int>;