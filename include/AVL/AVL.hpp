#ifndef AVL_H
#define AVL_H

template<class T>
struct Node {
    T   data;
    int balance;
    int height;
    Node<T> *left, *right, *parent;

    Node(const T& data);
    ~Node();
    
    bool  hasLeft() const;
    bool hasRight() const;
    bool   isLeft() const;
    bool  isRight() const;
        
    void setAttributes();
    void swap(Node<T>* other);
};

template<class T>
class AVL {
    private:
        int size;
        Node<T> *root;

        Node<T> *rotate(Node<T>* node);
        Node<T> *doubleRotation(Node<T>*const high, Node<T>*const middle, Node<T>*const low);
        Node<T> *simpleRotation(Node<T>*const high, Node<T>*const low);
        void reconstruct(Node<T>* node);
        Node<T> *inOrder(Node<T>* node);
    public:
        AVL();
        AVL(const T& data);

        // Insert newData in the tree.
        void insert(const T& newData);

        // If the tree is not empty, save the
        // minimum to &out and return true.        
        bool findMin(T& out) const;
        
        // Return the size of the tree.
        int getSize() const { return size; }

        // If num is in the tree, delete it
        // and return true.
        bool deleteNum(const T& num);

        // If val exists in the tree,
        // return SUCCESS.
        char *search(const T& val) const;
};

#include "AVL.cpp"

#endif // AVL_H