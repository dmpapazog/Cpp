#ifndef AVL_HPP
#define AVL_HPP

#include "AVL.hpp"
#include <iostream>
#include <cassert>

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
    // Will only perform if it has only one child
    assert(!(hasLeft() && hasRight()));

    // Will trigger if has left child.
    bool flag = false;

    // Has left child
    if (hasLeft()) {
        // set its parent to this node's parent.
        left->parent = parent;
        flag = true;

    // Has right child
    } else if (hasRight()) {
        // set its parent to this node's parent.
        right->parent = parent;
    }

    // If this node is left child
    if (isLeft()) {
        // reset this parent's left child based on flag.
        parent->left = flag ? left : right;
    
    // If this node is right child
    } else if (isRight()) {
        // reset this parent's right child based on flag.
        parent->right = flag ? left : right;
    }

    // Set this node's pointers to nullptr to avoid unwanted deletions/
    parent = left = right = nullptr;
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
    // Swap the data and the count of this node with the other.
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
void AVL<T>::treeDelete(Node<T>* node)
{
    if (node->hasLeft()) {
        treeDelete(node->left);
    }
    if (node->hasRight()) {
        treeDelete(node->right);
    }
    delete node;
}

template <class T>
AVL<T>::~AVL()
{
    if (root != nullptr) {
        treeDelete(root);
    }
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
        // The node is imbalanced because of the right subtree.
        if (node->right->balance == -1) {
            // The extra node is located at the right - right node.
            // Perform a simple rotation for the node and node->right.
            return simpleRotation(node, node->right);
        } else {
            // The extra node is located at the right - left node.
            // Perform a double rotation for the node, node->right and node->right->left.
            return doubleRotation(node, node->right, node->right->left);
        }
    } else {
        // The node is imbalanced because of the left subtree.
        if (node->left->balance == 1) {
            // The extra node is located at the left - left node.
            // Perform a simple rotation for the node and node->left.
            return simpleRotation(node, node->left);
        } else {
            // The extra node is located at the left - right node.
            // Perform a double rotation for the node, node->left and node->left->right.
            return doubleRotation(node, node->left, node->left->right);
        }
    }
}

template <class T>
Node<T>* AVL<T>::simpleRotation(Node<T>* const high, Node<T>* const low)
{
    // If low is high's right child
    if (low->isRight()) {
        // Perform a left rotation.

        high->right = low->left;
        // If low has a left child
        if (low->hasLeft()) {
            // set its parent to high node.
            low->left->parent = high;
        }
        low->left = high;
    } else {
        // Perform a right rotation.

        // If low has a right child
        high->left = low->right;
        if (low->hasRight()) {
            // set its parent to high node.
            low->right->parent = high;
        }
        low->right = high;
    }
    // Check if high has a parent and change its corresponding child pointer.
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
bool AVL<T>::findMax(T& out) const
{
    if (root == nullptr) {
        return false;
    }

    const Node<T>* it = root;
    while (it->hasRight()) {
        it = it->right;
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

    // The node to be deleted.
    Node<T>* it = temp;
    if (temp->hasLeft() && temp->hasRight()) {
        // Has 2 children. Starting from temp, find the first node 
        // by the in-order traversal and swap it with the initial one.
        it = inOrder(temp);
        it->swap(temp);
        // 'it' points to the node that will be deleted. Because of the
        // swap, the 'it' will have at most 1 child.
    }

    // Setting the root of the tree to its proper new value
    if (root == it) {
        if (it->hasLeft()) {
            root = it->left;
        } else if (it->hasRight()) {
            root = it->right;
        } else {
            root = it->parent;
        }
    }

    temp = it->parent;
    delete it;
    reconstruct(temp);
    size--;
    return true;
}
} // namespace std
#endif // AVL_HPP
