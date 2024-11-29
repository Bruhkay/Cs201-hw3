#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node class template
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {

public:
    LinkedList();     // Constructor
    ~LinkedList();    // Destructor

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertSorted(T value); // Inserts in ascending order
    void deleteByValue(T value);
    void display() const;
    Node<T>* getHead() const;
    void setHead(Node<T>* head);
private:
    Node<T>* head;
};

#endif // LINKEDLIST_H