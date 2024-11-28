#include "LinkedList.h"

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        //delete temp; //TODO
    }
}


// Insert a node at the end
template <typename T>
void LinkedList<T>::insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert a node in sorted order (ascending)
template <typename T>
void LinkedList<T>::insertSorted(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (!head || (head->data).getID() > value.getID()) { // Insert at the beginning
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next && temp->next->data.getID() < value.getID()) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Get the head of the list
template <typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

// Set the head of the list
template <typename T>
void LinkedList<T>::setHead(Node<T>* newHead) {
    head = newHead;
}