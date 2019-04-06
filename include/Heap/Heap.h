#ifndef HEAP_H
#define HEAP_H

template <class T, class Comparator>
class Heap {
private:
    // The full size of the heap.
    int capacity;

    // The number of the elements in the heap.
    int size;
    T* data;

    void heapifyUp();
    void heapifyDown();
    void swap(T& a, T& b);

public:
    Heap();
    Heap(const int& size);
    Heap(const Heap& old);
    ~Heap();

    // Return the index of the left child.
    int   getLeft(const int& parent) const;
    // Return the index of the right child.
    int  getRight(const int& parent) const;
    // Return the index of the parent.
    int getParent(const int& child)  const;

    // Return false if the heap is full.
    bool insert(const T& insertion);

    // If the heap is not empty, save the
    // top of the heap and return true.
    bool extract(T& out);

    // If the heap is not empty, delete
    // the top node and return true.
    bool removeTop();
    void show() const;
};

#include "Heap.hpp"

#endif // HEAP_H