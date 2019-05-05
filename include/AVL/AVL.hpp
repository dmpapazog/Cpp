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

    // The number of appearences of the number in the tree.
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

    // Perform a double rotation between high, middle and low nodes and return the node with the lowest height.
    Node<T>* doubleRotation(Node<T>* const high, Node<T>* const middle, Node<T>* const low);

    // Perform a simple rotation between high and low nodes and return the node with the lowest height.
    Node<T>* simpleRotation(Node<T>* const high, Node<T>* const low);

    // Reconstruct the tree starting from node until reaching the root of the tree.
    void        reconstruct(Node<T>* node);

    Node<T>*        inOrder(Node<T>* node);
    void       printInOrder(Node<T>* node) const;
    void     printPostOrder(Node<T>* node) const;
    void      printPreOrder(Node<T>* node) const;

public:
    AVL();
    AVL(const T& importData);

    // Insert newData in the tree.
    void insert(const T& newData);

    // If the tree is not empty, save the minimum to &out and return true.
    bool findMin(T& out) const;

    // Return the size of the tree.
    int getSize() const { return size; }

    // If num is in the tree, delete it and return true.
    bool deleteNum(const T& num);

    // If val exists in the tree, return SUCCESS.
    string search(const T& val) const;

    // Print the tree be in-order traversal.
    void printIn()   const;
    // Print the tree be pre-order traversal.
    void printPre()  const;
    // Print the tree be post-order traversal.
    void printPost() const;
};

} // namespace std

#include "AVL.cpp"

#endif // AVL_H
