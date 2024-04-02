#include "node.cpp"
#include <cstddef>

// Header file for the List class
template <typename Item_Type>
class List
{
  private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    std::size_t num_items;
  public:
    // Constructor
    List();
    // Destructor
    ~List();
    // Inserts a copy of item as the first element of the list.
    void push_front(const Item_Type& item);
    // Adds a copy of item to the end of the list.
    void push_back(const Item_Type& item);
    // Removes the first item from the list.
    void pop_front();
    // Removes the last item from the list.
    void pop_back();
    // Gets the first element in the list. Both constant and modifiable versions are provided.
    Item_Type& front();
    // Gets the last element in the list. Both constant and modifiable versions are provided.
    Item_Type& back();
    // Returns true if this list is empty.
    bool empty() const;
    // Insert item at position index (starting at 0). Insert at the end if index is beyond the end of the list.
    void insert(std::size_t index, const Item_Type& item);
    // Remove the item at position index. Return true if successful; return false if index is beyond the end of the list.
    bool remove(std::size_t index);
    // Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.
    std::size_t find(const Item_Type& item);
    // Pretty print the list
    void pretty_print();
};
