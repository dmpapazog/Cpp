#ifndef AVL_H
#define AVL_H

#include <string>

namespace std {

template <class T>
struct Node {
    // Maximum height between the left and the right sub-trees.
    int subHeight;

    // The difference between the heights of the left and the right sub-trees.
    int balance;

    // The number of appearences of the data in the tree.
    unsigned int count;

    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    T data;

    Node(const T& data);
    ~Node();

    // Return true of the node has left child.
    bool hasLeft()  const;

    // Return true if the node has right child.
    bool hasRight() const;

    // Return true if the node has a parent and is left child.
    bool isLeft()   const;

    // Return true if the node has a parent and is right child.
    bool isRight()  const;

    // Set the height and the balance of this node.
    void setAttributes();
    // Swap the contents of this node with the other.
    void swap(Node<T>* other);
};

template <class T>
class AVL {
private:
    // The multitude of the nodes the tree has.
    int size;
    // If not nullptr, pointing to the root of the tree.
    Node<T>* root;

    // Perform the necessary rotation and return the node with the lowest height.
    Node<T>*         rotate(Node<T>* node);

    // Perform a double rotation between high, middle and low nodes and return the node with the lowest height (closest to the root).
    Node<T>* doubleRotation(Node<T>* const high, Node<T>* const middle, Node<T>* const low);

    // Perform a simple rotation between high and low nodes and return the node with the lowest height (closest to the root).
    Node<T>* simpleRotation(Node<T>* const high, Node<T>* const low);

    // Reconstruct the tree starting from node until reaching the root of the tree.
    void        reconstruct(Node<T>* node);

    Node<T>*        inOrder(Node<T>* node);

    // Delete the tree
    void treeDelete(Node<T>* node);

public:
    AVL();
    AVL(const T& importData);
    ~AVL();

    // Insert newData in the tree.
    void insert(const T& newData);

    // If the tree is not empty, save the minimum to &out and return true.
    bool findMin(T& out) const;
    
    // If the tree is not empty, save the maximum to &out and return true.
    bool findMax(T& out) const;

    // Return the size of the tree.
    int getSize() const { return size; }

    // If num is in the tree, delete it and return true.
    bool deleteNum(const T& num);

    // If val exists in the tree, return SUCCESS.
    string search(const T& val) const;
};

} // namespace std

#include "AVL.cpp"

#endif // AVL_H
