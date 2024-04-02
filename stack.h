#include <cstddef>
#include <vector>

class Stack {
  public:
    Stack();
    bool empty() const;
    void push(int item);
    int pop();
    int peek_top() const;
    // Get the average of the stack
    double average() const;
    void pretty_print() const;
  private:
    std::vector<int> items;
};