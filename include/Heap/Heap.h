#ifndef HEAP_H
#define HEAP_H

template <class T, class Comparator>
class Heap {
private:
    // The full size of the heap.
    int capacity;

    // The number of the elements in the heap.
    // It points to the first free position of the heap.
    int size;
    T* data;

    // Used by insertion. Restructrures the heap.
    void heapifyUp();
    
    // Used by removeTop. Restructures the heap.
    void heapifyDown();
    void swap(T& a, T& b);

    // Return the index of the left child.
    int   getLeft(const int& parent) const;
    // Return the index of the right child.
    int  getRight(const int& parent) const;
    // Return the index of the parent.
    int getParent(const int& child)  const;

public:
    Heap();
    Heap(const int& size);
    Heap(const Heap& old);
    ~Heap();

    // If the heap is not full, add the 
    // insertion to the heap and return true.
    bool insert(const T& insertion);

    // If the heap is not empty, save the
    // top of the heap to out and return true.
    bool extract(T& out);

    // If the heap is not empty, delete
    // the top node and return true.
    bool removeTop();
};

#include "Heap.cxx"

#endif // HEAP_H