#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
struct Node {
  Node* prev = nullptr;
  Node* next = nullptr;
  int data = 0;
};
class LinkedList {
 public:
  int size;
  Node* head;
  Node* tail;
  LinkedList();
  void Insert(int data);
  void InsertAfter(int data, int afterData);
  void InsertBefore(int data, int beforeData);
  int GetCount();
  int GetDataByIndex(int index);
  void Remove();
  void Display();
  ~LinkedList();
};
#endif