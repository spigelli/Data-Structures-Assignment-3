#include "queue.cpp"
#include "linear_search.cpp"
#include "test.h"
#include <iostream>
using namespace std;

void test_testing() {
  TestSuite suite("Testing Suite Tester");
  // Anonymous function that will never throw
  suite.addTest("Test that always passes", []() {});
  // Anonymous function that will always throw
  suite.addTest("Test that always fails", []() { throw std::runtime_error("This test always fails"); });
  suite.run();
}

int get_rand_int_() {
  return rand() % 100;
}

Queue<int>* create_ten_int_queue() {
  Queue<int>* q;
  q = new Queue<int>();
  for (int i = 0; i < 10; i++) {
    q->push(get_rand_int_());
  }
  return q;
}

void test_queue() {
  TestSuite suite("Queue Tests");
  // Instantiate and add ten integers to the queue
  suite.addTest("Create a queue with ten integers", []() {
    cout << endl;
    Queue<int>* q = create_ten_int_queue();
    q->pretty_print();
    delete q;
  });
  // Display the queue using pop
  suite.addTest("Display all elements using member functions", []() {
    cout << endl;
    Queue<int>* q = create_ten_int_queue();
    std::cout << "Initial queue: ";
    q->pretty_print();
    std::cout << endl << "Popping all elements: ";
    while (!q->empty()) {
      cout << q->pop() << endl;
    }
    delete q;
  });
  // Test the move_to_rear function
  suite.addTest("Test the move_to_rear function", []() {
    cout << endl;
    Queue<int>* q = create_ten_int_queue();
    std::cout << "Initial queue: ";
    q->pretty_print();
    std::cout << endl << "Moving the front to the rear: ";
    q->move_to_rear();
    q->pretty_print();
    delete q;
  });
  suite.run();
}

void test_linear_search() {
  TestSuite suite("Linear Search Tests");
  // Create a vector of 15 random integers
  suite.addTest("Create a vector of 15 random integers", []() {
    std::cout << "Creating a vector of 15 random integers" << std::endl;
    vector<int> v = create_vector();
    std:: cout << "Vector: ";
    pretty_print_vector(v);
  });
  // Test the linear search function
  suite.addTest("Test the linear search function", []() {
    vector<int> v = create_vector();
    // pretty_print_vector(v);
    int target = get_random_int();
    cout << "Target: " << target << endl;
    int pos = init_linear_search(v, target);
    cout << "Position of last occurrence of target: " << pos << endl;
  });
  suite.run();
}

int main() {
  test_testing();
  test_queue();
  test_linear_search();
  return 0;
}
