#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template<typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val);
    };

    Node* head;

public:
    DoublyLinkedList();
    void insertSorted(T value);
    void printList();
};

#endif // DOUBLY_LINKED_LIST_H
