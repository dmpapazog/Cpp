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
    subHeight = balance = 0;
    count = 1;
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
    return (parent != nullptr) && (parent->left == this);
}

template <class T>
bool Node<T>::isRight() const
{
    return (parent != nullptr) && (parent->right == this);
}

template <class T>
void Node<T>::setAttributes()
{
    int leftH, rightH;
    leftH = rightH = 0;
    if (hasLeft()) {
        leftH += 1 + left->subHeight;
    }
    if (hasRight()) {
        rightH += 1 + right->subHeight;
    }
    subHeight = leftH > rightH ? leftH : rightH;
    balance = leftH - rightH;
}

template <class T>
void Node<T>::swap(Node<T>* other)
{
    T temp = other->data;
    other->data = this->data;
    this->data = temp;

    int temp2 = other->count;
    other->count = this->count;
    this->count = temp2;
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
    while (true) {
        if (newData < it->data) {
            if (!it->hasLeft()) {
                it->left = newNode;
                break;
            }
            it = it->left;
        } else if (newData == it->data) {
            it->count++;
            size++;
            delete newNode;
            return;
        } else {
            if (!it->hasRight()) {
                it->right = newNode;
                break;
            }
            it = it->right;
        }
    }
    newNode->parent = it;

    reconstruct(it);
    size++;
}

template <class T>
void AVL<T>::reconstruct(Node<T>* node)
{
    if (node != nullptr) {
        node->setAttributes();
        if (node->balance < -1 || node->balance > 1) {
            node = rotate(node);
        }
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
        cout << "\nGoing to left";
    }
    out = it->data;
    return true;
}

template <class T>
string AVL<T>::search(const T& val) const
{
    const Node<T>* it = root;
    while (it != nullptr) {
        if (val == it->data) {
            return ("SUCCESS"s);
        }
        it = val < it->data ? it->left : it->right;
    }
    return ("FAILURE"s);
}

template <class T>
Node<T>* AVL<T>::inOrder(Node<T>* node)
{
    Node<T>* it = node->right;
    while (it->hasLeft()) {
        it = it->left;
    }
    return it;
}

template <class T>
void AVL<T>::printIn() const
{
    if (root != nullptr) {
        printInOrder(root);
    }
}

template <class T>
void AVL<T>::printPre() const
{
    if (root != nullptr) {
        printPreOrder(root);
    }
}
template <class T>
void AVL<T>::printPost() const
{
    if (root != nullptr) {
        printPostOrder(root);
    }
}

template <class T>
void AVL<T>::printInOrder(Node<T>* node) const
{
    if (node->hasLeft()) {
        printInOrder(node->left);
    }
    cout << ' ' << node->data << '(' << node->count << ')';
    if (node->hasRight()) {
        printInOrder(node->right);
    }
}

template <class T>
void AVL<T>::printPreOrder(Node<T>* node) const
{
    cout << ' ' << node->data << '(' << node->count << ')';
    if (node->hasLeft()) {
        printPreOrder(node->left);
    }
    if (node->hasRight()) {
        printPreOrder(node->right);
    }
}

template <class T>
void AVL<T>::printPostOrder(Node<T>* node) const
{
    if (node->hasLeft()) {
        printPostOrder(node->left);
    }
    if (node->hasRight()) {
        printPostOrder(node->right);
    }
    cout << ' ' << node->data << '(' << node->count << ')';
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

    if (--temp->count > 0) {
        size--;
        return true;
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
        if (root == it) {
            root = it->left;
        }

        // Has only right child.
    } else if (it->hasRight()) {
        it->right->parent = it->parent;
        if (it->isLeft()) {
            it->parent->left = it->right;
        } else if (it->isRight()) {
            it->parent->right = it->right;
        }
        if (root == it) {
            root = it->right;
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
    if (--size == 0) {
        root = nullptr;
    }
    return true;
}
} // namespace std
#endif // AVL_HPP
