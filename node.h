// Header file for the node class which is generic

template <typename Item_Type>
class Node {
  private:
    // Data members
    Item_Type data;
    Node* next;
  public:
    // Constructor
    Node(Item_Type data, Node* next);
    // Destructor
    ~Node();
    // Getters and setters
    Item_Type& getData();
    Node* getNext();
    void setData(Item_Type data);
    void setNext(Node* next);
};
