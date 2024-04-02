#include "queue.cpp"
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
    Queue<int>* q = create_ten_int_queue();
    q->pretty_print();
    delete q;
  });
  suite.run();
}

int main() {
  test_testing();
  test_queue();
  return 0;
}
