#include "queue.h"
#include <iostream>
#include <fstream>

/*
template <typename Item_Type>
class Queue
{
  private:
    std::size_t num_items;
    Node<Item_Type>* front_of_queue;
    Node<Item_Type>* back_of_queue;
  public:
    // Constructor
    Queue();
    // Destructor
    ~Queue();
    // Inserts a copy of item at the back of the queue.
    void push(const Item_Type& item);
    // Removes the first item from the queue and returns it.
    Item_Type pop();
    // Gets the first element in the queue.
    Item_Type front();
    // Returns true if this queue is empty.
    bool empty() const;
    // Returns the number of items in the queue.
    std::size_t size() const;
    // Pretty print the queue
    void pretty_print();
};
*/

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
  Item_Type item = front_of_queue->getItem();
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
  return front_of_queue->getItem();
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
    std::cout << current->getItem();
    if (i !== 0) {
      std::cout << ", ";
    }
    current = front_of_queue;
  }
  std::cout << "] <- Front" << std::endl;
}

template class Queue<int>;