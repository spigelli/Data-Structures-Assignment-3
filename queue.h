#include "list.cpp"
#include <cstddef>

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
    // Moves the front of the queue to the back of the queue.
    void move_to_rear();
};