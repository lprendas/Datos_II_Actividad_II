#include "BinarySearchTree.h"
#include <iostream>

template<typename T>
BinarySearchTree<T>::Node::Node(T val) : data(val), left(nullptr), right(nullptr) {}

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert(Node* node, T value) {
    if (!node) return new Node(value);
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

template<typename T>
void BinarySearchTree<T>::insert(T value) {
    root = insert(root, value);
}

template<typename T>
void BinarySearchTree<T>::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}

template<typename T>
void BinarySearchTree<T>::printInOrder() {
    inOrder(root);
    std::cout << std::endl;
}

// Instanciamos la plantilla
template class BinarySearchTree<int>;
