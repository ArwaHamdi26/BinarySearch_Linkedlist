#include "../include/LinkedList.hpp"

#include <iostream>
using namespace std;
LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

void LinkedList::Insert(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr) {
    newNode->prev = nullptr;
    head = newNode;
    tail = newNode;
    return;
  }
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

void LinkedList::InsertAfter(int data, int afterData) {
  Node *current = head;
  if (head == nullptr) {
    cout << "LinkedList is empty";
    return;
  }
  while (current != nullptr) {
    if (current == tail && current->data == data) {
      Node *newNode = new Node;
      tail->next = newNode;
      newNode->data = afterData;
      newNode->prev = tail;
      newNode->next = nullptr;
      tail = newNode;
      return;
    } else if (current->data == data) {
      Node *newNode = new Node;
      newNode->data = afterData;
      current->next->prev = newNode;
      newNode->next = current->next;
      current->next = newNode;
      newNode->prev = current;
      return;
    }
    current = current->next;
  }
  cout << "this data doesn't exist";
}

void LinkedList::InsertBefore(int data, int beforeData) {
  if (head == nullptr) {
    cout << "LinkedList is empty" << endl;
    return;
  }

  Node *current = head;
  while (current != nullptr) {
    if (current == head && current->data == data) {
      Node *newNode = new Node;
      newNode->data = beforeData;
      current->prev = newNode;
      newNode->next = current;
      newNode->prev = nullptr;
      head = newNode;
      return;
    } else if (current->data == data) {
      Node *newNode = new Node;
      newNode->data = beforeData;
      newNode->prev = current->prev;
      if (current->prev != nullptr) {
        current->prev->next = newNode;
      }
      current->prev = newNode;
      newNode->next = current;
      return;
    }
    current = current->next;
  }
  cout << "this data doesn't exist";
}
int LinkedList::GetCount() {
  int counter = 0;
  Node *current = head;
  if (head == nullptr) {
    cout << "LinkedList is empty" << endl;
    return 0;
  }
  while (current != nullptr) {
    counter++;
    current = current->next;
  }
  return counter;
}

int LinkedList::GetDataByIndex(int index) {
  if (index < 0) {
    cout << "Invalid index" << endl;
    return -1;
  } else if (head == nullptr) {
    cout << "linked list is empty";
    return -1;
  } else {
    Node *current = head;
    int currIndex = 0;
    while (current != nullptr) {
      if (currIndex == index) {
        return current->data;
      }
      current = current->next;
      currIndex++;
    }
    return -1;
  }
}

void LinkedList::Remove() {
  if (head == nullptr) {
    cout << "LinkedList is empty" << endl;
    return;
  }
  head->data = 0;
  head = head->next;
}
void LinkedList::Display() {
  if (head == nullptr) {
    cout << "LinkedList is empty" << endl;
    return;
  }

  Node *current = head;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->next;
  }
}

LinkedList::~LinkedList() {
  Node *current = head;
  while (current != nullptr) {
    Node *nextNode = current->next;
    delete current;
    current = nextNode;
  }
  head = nullptr;
  tail = nullptr;
}