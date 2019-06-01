#ifndef HEAP_CXX
#define HEAP_CXX

#include "Heap.h"

using namespace std;

template<class T, class Comparator>
int Heap<T, Comparator>::getLeft(const int& parent) const
{
    return parent * 2 + 1;
}

template<class T, class Comparator>
int Heap<T, Comparator>::getRight(const int& parent) const
{
    return parent * 2 + 2;
}

template<class T, class Comparator>
int Heap<T, Comparator>::getParent(const int& child) const
{
    return (child - 1) / 2;
}

template<class T, class Comparator>
Heap<T, Comparator>::Heap()
{
    size     = 0;
    capacity = 0;
    data     = nullptr;
}

template<class T, class Comparator>
Heap<T, Comparator>::Heap(const int& capacity)
{
    this->capacity = capacity;
    this->size     = 0;
    data = new T[this->capacity];
}

template<class T, class Comparator>
Heap<T, Comparator>::Heap(const Heap& old)
{
    this->capacity = old.capacity;
    this->size     = old.size;
    this->data     = new T[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->data[i] = old.data[i];
    }
}

template<class T, class Comparator>
Heap<T, Comparator>::~Heap()
{
    delete[] data;
}

template<class T, class Comparator>
void Heap<T, Comparator>::heapifyUp()
{
    // Start from the bottom of the heap
    int index  = size - 1;
    int parent = getParent(index);

    Comparator comp;
    // While we are in the heap and comp is true bettween the child and the parent
    // (child is lesser or greater than the parent)
    while (index > 0 && comp(data[index], data[parent])) {
        // swap them and continue from the parent
        swap(data[index], data[parent]);

        index  = parent;
        parent = getParent(index);
    }
}

template<class T, class Comparator>
void Heap<T, Comparator>::heapifyDown()
{
    int index = 0;
    int left  = getLeft(index);
    int right = getRight(index);

    Comparator comp;
    // While left child is in the heap
    while (left < size) {
        int child;
        // check for which child comp is true
        if (right < size && comp(data[right], data[left])) {
            child = right;
        } else {
            child = left;
        }

        // If comp between the child and the index is true
        // (child is lesser or greater than the parent)
        if (comp(data[child], data[index])) {
            // swap them and continue from the child
            swap(data[child], data[index]);

            index = child;
            left  = getLeft(index);
            right = getRight(index);
            continue;
        }
        break;
    }
}

template<class T, class Comparator>
bool Heap<T, Comparator>::insert(const T& insertion)
{
    if (size == capacity) {
        return false;
    }
    data[size++] = insertion;
    heapifyUp();
    return true;
}

template<class T, class Comparator>
bool Heap<T, Comparator>::extract(T& out)
{
    if (size == 0) {
        return false;
    }
    out = data[0];
    return true;
}

template<class T, class Comparator>
void Heap<T, Comparator>::swap(T& a, T& b)
{
    T temp = a;
      a    = b;
      b    = temp;
}

template<class T, class Comparator>
bool Heap<T, Comparator>::removeTop()
{
    if (size == 0) {
        return false;
    }
    swap(data[0], data[--size]);
    heapifyDown();
    return true;
}

#endif // HEAP_CXX