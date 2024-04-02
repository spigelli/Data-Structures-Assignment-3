/**
 * Prompt: Write a recursive linear search function with a recursive step that finds the last
 * occurrence of a target in a vector, not the first. You will need to modify the linear search
 * function (You can find it in the slides Lecture 9 slide 30)
 * 
 * Initial linear search function:
 * int linear_search(vector<Item_Type>& items, Item_Type&target, size_t pos_first) {
 *   if (pos_first == items.size())
 *   return -1;
 *   if (target == items[pos_first])
 *   return pos_first;
 *   else
 *   return linear_search(items, target, pos_first + 1);
 * }
 */

#include <iostream>
#include <vector>

using namespace std;

int get_random_int() {
  return rand() % 7;
}

vector<int> create_vector() {
  vector<int> v;
  for (int i = 0; i < 15; i++) {
    v.push_back(get_random_int());
  }
  return v;
}

void pretty_print_vector(vector<int>& v) {
  cout << "{";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1) {
      cout << ", ";
    }
  }
  cout << "}";
  cout << endl;
}

int linear_search(vector<int>& items, int target, size_t pos) {
  // Find the next occurrence of the target
  if (pos == -1) {
    return -1;
  }
  // If the target is found, return the position
  if (items[pos] == target) {
    return pos;
  }
  return linear_search(items, target, pos - 1);
}

int init_linear_search(vector<int>& items, int target) {
  return linear_search(items, target, items.size() - 1);
}
