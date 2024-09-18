#include "doubly_linked_list.h"
#include <iostream>

template<typename T>
DoublyLinkedList<T>::Node::Node(T val) : data(val), prev(nullptr), next(nullptr) {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr) {}

template<typename T>
void DoublyLinkedList<T>::insertSorted(T value) {
    Node* newNode = new Node(value);
    if (!head || head->data >= value) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next) newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

template<typename T>
void DoublyLinkedList<T>::printList() {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Instanciamos la plantilla
template class DoublyLinkedList<int>;
