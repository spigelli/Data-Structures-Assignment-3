/**
 * Insertion sort
 * Prompt: Modify the source code for the insertion sort so that it can sort a list of integers
 * (You can find the source code on lecture 10 slide 138
 * 
 * Initial insertion sort function:
 * 
 * void insertion_sort(std::vector<int> &num)
 * {
 *   int i, j, key;
 *   bool insertionNeeded = false;
 *   for (j = 1; j < num.size(); j++)
 *   {
 *     key = num[j];
 *     insertionNeeded = false;
 *     for (i = j - 1; i >= 0; i--)
 *     {
 *       if (key < num[i])
 *       {
 *         num[i + 1] = num[i]; // larger values move right
 *         insertionNeeded = true;
 *       }
 *       else
 *         break;
 *     }
 *     if (insertionNeeded)
 *       num[i + 1] = key; // Put key into its proper location
 *   }
 * }
*/
#include <iostream>

using namespace std;

void insertion_sort(List<int>* num) {
  int i, j, key;
  bool insertionNeeded = false;
  for (j = 1; j < num->size(); j++) {
    key = num->get(j);
    insertionNeeded = false;
    for (i = j - 1; i >= 0; i--) {
      if (key < num->get(i)) {
        // num->set(i + 1, num->get(i)); // larger values move right
        // We only have insert and remove functions
        num->remove(i+1);
        num->insert(i + 1, num->get(i));
        insertionNeeded = true;
      } else {
        break;
      }
    }
    if (insertionNeeded) {
      // num->set(i + 1, key); // Put key into its proper location
      num->remove(i+1);
      num->insert(i + 1, key);
    }
  }
}