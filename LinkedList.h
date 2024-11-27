#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node class template
template <typename T>
class Node {
public:
    T data;           // The data stored in the node
    Node* next;       // Pointer to the next node in the list

    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class template
template <typename T>
class LinkedList {
private:
    Node<T>* head;    // Pointer to the head of the list

public:
    LinkedList();     // Constructor
    ~LinkedList();    // Destructor

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertSorted(T value); // Inserts in ascending order
    void deleteByValue(T value);
    void display() const;
    Node<T>* getHead() const;
};

#endif // LINKEDLIST_H