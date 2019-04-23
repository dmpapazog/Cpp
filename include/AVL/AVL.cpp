#ifndef AVL_HPP
#define AVL_HPP

#include "AVL.hpp"
#include <iostream>

namespace std {

template <class T>
Node<T>::Node(const T& importData)
{
    this->data = importData;
    parent = left = right = nullptr;
    height = balance = 0;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
bool Node<T>::hasLeft() const
{
    return left != nullptr;
}

template <class T>
bool Node<T>::hasRight() const
{
    return right != nullptr;
}

template <class T>
bool Node<T>::isLeft() const
{
    if (parent == nullptr) {
        return false;
    }
    return parent->left == this;
}

template <class T>
bool Node<T>::isRight() const
{
    if (parent == nullptr) {
        return false;
    }
    return parent->right == this;
}

template <class T>
void Node<T>::setAttributes()
{
    int leftH, rightH;
    leftH = rightH = 0;
    if (hasLeft()) {
        leftH += 1 + left->height;
    }
    if (hasRight()) {
        rightH += 1 + right->height;
    }
    height = leftH > rightH ? leftH : rightH;
    balance = leftH - rightH;
}

template <class T>
void Node<T>::swap(Node<T>* other)
{
    T temp = other->data;
    other->data = this->data;
    this->data = temp;
}

template <class T>
AVL<T>::AVL()
{
    size = 0;
    root = nullptr;
}

template <class T>
AVL<T>::AVL(const T& data)
{
    root = new Node<T>(data);
    size = 1;
}

template <class T>
void AVL<T>::insert(const T& newData)
{
    auto newNode = new Node<T>(newData);
    if (root == nullptr) {
        root = newNode;
        size++;
        return;
    }

    Node<T>* it = root;
    bool flag = false;
    while (true) {
        if (newData < it->data) {
            if (!it->hasLeft()) {
                flag = true;
                break;
            }
            it = it->left;
        } else {
            if (!it->hasRight()) {
                break;
            }
            it = it->right;
        }
    }

    newNode->parent = it;
    if (flag) {
        it->left = newNode;
    } else {
        it->right = newNode;
    }

    reconstruct(it);
    size++;
}

template <class T>
void AVL<T>::reconstruct(Node<T>* node)
{
    node->setAttributes();
    if (node->balance < -1 || node->balance > 1) {
        node = rotate(node);
    }
    if (node->parent != nullptr) {
        reconstruct(node->parent);
    }
}

template <class T>
Node<T>* AVL<T>::rotate(Node<T>* node)
{
    if (node->balance == -2) {
        if (node->right->balance == -1) {
            return simpleRotation(node, node->right);
        } else {
            return doubleRotation(node, node->right, node->right->left);
        }
    } else {
        if (node->left->balance == 1) {
            return simpleRotation(node, node->left);
        } else {
            return doubleRotation(node, node->left, node->left->right);
        }
    }
}

template <class T>
Node<T>* AVL<T>::simpleRotation(Node<T>* const high, Node<T>* const low)
{
    if (low->isRight()) {
        high->right = low->left;
        if (low->hasLeft()) {
            low->left->parent = high;
        }
        low->left = high;
    } else {
        high->left = low->right;
        if (low->hasRight()) {
            low->right->parent = high;
        }
        low->right = high;
    }
    if (high->isLeft()) {
        high->parent->left = low;
    } else if (high->isRight()) {
        high->parent->right = low;
    }
    low->parent = high->parent;
    high->parent = low;
    if (low->parent == nullptr) {
        root = low;
    }

    high->setAttributes();
    low->setAttributes();
    return low;
}

template <class T>
Node<T>* AVL<T>::doubleRotation(Node<T>* const high, Node<T>* const middle, Node<T>* const low)
{
    simpleRotation(middle, low);
    return simpleRotation(high, low);
}

template <class T>
bool AVL<T>::findMin(T& out) const
{
    if (root == nullptr) {
        return false;
    }

    const Node<T>* it = root;
    while (it->hasLeft()) {
        it = it->left;
    }
    out = it->data;
    return true;
}

template <class T>
char* AVL<T>::search(const T& val) const
{
    const Node<T>* it = root;
    while (it != nullptr) {
        if (val == it->data) {
            return const_cast<char* const>("SUCCESS");
        }
        it = val < it->data ? it->left : it->right;
    }
    return const_cast<char* const>("FAILURE");
}

template <class T>
Node<T>* AVL<T>::inOrder(Node<T>* node)
{
    Node<T>* it = node;
    if (!it->hasRight()) {
        return node;
    }
    it = it->right;
    while (it->hasLeft()) {
        it = it->left;
    }
    return it;
}

template <class T>
bool AVL<T>::deleteNum(const T& num)
{
    Node<T>* temp = root;
    while (true) {
        if (temp == nullptr) {
            return false;
        }
        if (num == temp->data) {
            break;
        }
        temp = num < temp->data ? temp->left : temp->right;
    }

    Node<T>* it = temp;
    // Has 2 children.
    if (temp->hasLeft() && temp->hasRight()) {
        it = inOrder(temp);
        it->swap(temp);
    }

    // Has only left child.
    if (it->hasLeft()) {
        it->left->parent = it->parent;
        if (it->isLeft()) {
            it->parent->left = it->left;
        } else if (it->isRight()) {
            it->parent->right = it->left;
        }

        // Has only right child.
    } else if (it->hasRight()) {
        it->right->parent = it->parent;
        if (it->isLeft()) {
            it->parent->left = it->right;
        } else if (it->isRight()) {
            it->parent->right = it->right;
        }

        // Hasn't any children.
    } else {
        if (it->isLeft()) {
            it->parent->left = nullptr;
        } else if (it->isRight()) {
            it->parent->right = nullptr;
        }
    }
    reconstruct(it->parent);

    delete it;
    size--;
    return true;
}
} // namespace std
#endif // AVL_HPP
