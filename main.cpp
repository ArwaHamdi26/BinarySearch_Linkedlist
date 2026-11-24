#include <iostream>

#include "./include/LinkedList.hpp"
using namespace std;
Node* middle(Node* start, Node* last) {
  if (start == last) {
    return nullptr;
  }
  Node* slow = start;
  Node* fast = start;
  while (fast != last && fast->next != last) {
    slow = slow->next;
    fast = fast->next;

    if (fast != last) {
      fast = fast->next;
    }
  }
  return slow;
}
bool BinarySearch(LinkedList& l, int n) {
  Node* start = l.head;
  Node* last = nullptr;
  while (start != last) {
    Node* midNode = middle(start, last);
    if (midNode == nullptr) return false;
    if (midNode->data == n) {
      return true;
    } else if (midNode->data < n) {
      start = midNode->next;
    } else {
      last = midNode;
    }
  }

  /*int min = 0;
int max = size - 1;
while (min <= max) {
  int midIndex = min + (max - min) / 2;
  if (n == arr[midIndex]) {
    return midIndex;
  } else if (n < arr[midIndex]) {
    max = midIndex - 1;
  } else {
    min = midIndex + 1;
  }
}*/
  return false;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  LinkedList m;

  m.Insert(2);
  m.Insert(3);
  m.Insert(9);
  m.Insert(12);
  m.Insert(17);
  m.Insert(20);
  m.Insert(26);
  m.Insert(31);

  bool x = BinarySearch(m, 2);

  bool y = BinarySearch(m, 31);
  bool z = BinarySearch(m, 12);
  bool f = BinarySearch(m, 6);
  cout << x << " " << y << " " << z << " " << f << endl;

  // int x = BinarySearch(arr, 8, 8);
  // cout << x << endl;
  return 0;
}
