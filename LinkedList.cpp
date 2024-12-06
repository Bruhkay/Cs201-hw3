#include "LinkedList.h"

template <typename T>
Node<T>::Node(T* value) : data(value), next(nullptr) {

}

template <typename T>
Node<T>::~Node() {
    data = nullptr;
    next = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}
template <typename T>
void LinkedList<T>::deleteByValue(T value) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data->getID() == value->getID()) {
        Node<T>* temp = head;
        head = head->next;
        cout << "Deleting head node: " << temp->data->getID() << endl; // Debug
        delete temp;
        return;
    }

    Node<T>* temp = head;
    while (temp->next && temp->next->data->getID() != value->getID()) {
        temp = temp->next;
    }

    if (temp->next) {
        Node<T>* nodeToDelete = temp->next;
        Node<T>* nextNode = temp->next->next;
        cout << "Deleting node: " << nodeToDelete->data->getID() << endl; // Debug
        delete nodeToDelete;
        temp->next = nextNode;

    } else {
        cout << "Value not found in the list." << endl;
    }
}
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

template <typename T>
void LinkedList<T>::insertSorted(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (!head || head->data->getID() > value->getID()) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next && temp->next->data->getID() < value->getID()) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
template <typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

template <typename T>
void LinkedList<T>::deleteList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
