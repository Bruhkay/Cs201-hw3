#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    Node* data;
    Node* next;

    Node(T* value);
    ~Node();
};

template <typename T>
class LinkedList {

public:
    LinkedList();     // Constructor
    ~LinkedList();    // Destructor

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertSorted(T value);
    void deleteByValue(T value);
    void display() const;
    Node<T>* getHead() const;
    void setHead(Node<T>* head);
    void deleteList();
private:
    Node<T>* head;
};

#endif // LINKEDLIST_H