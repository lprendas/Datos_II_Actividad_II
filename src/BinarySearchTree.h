#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template<typename T>
class BinarySearchTree {
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val);
    };

    Node* root;

    Node* insert(Node* node, T value);
    void inOrder(Node* node);

public:
    BinarySearchTree();
    void insert(T value);
    void printInOrder();
};

#endif // BINARY_SEARCH_TREE_H
