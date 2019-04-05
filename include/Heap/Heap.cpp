#include "Heap.h"
#include <iostream>

// getLeft:  indexParent * 2 + 1
// getRight: indexParent * 2 + 2

// getParent: (indexChild - 1) / 2

template<class T, typename Compare>
int Heap<T, Compare>::getLeft(const int& parent) const
{
    return parent * 2 + 1;
}

template<class T, typename Compare>
int Heap<T, Compare>::getRight(const int& parent) const
{
    return parent * 2 + 2;
}

template<class T, typename Compare>
int Heap<T, Compare>::getParent(const int& child) const
{
    return (child - 1) / 2;
}

template<class T, typename Compare>
Heap<T, Compare>::Heap()
{
    size = 0;
    data = nullptr;
    mask = nullptr;
}

template<class T, typename Compare>
Heap<T, Compare>::Heap(const int& size)
{
    this->size = size;
    data = new T[this->size];
    mask = new bool[this->size];
    for (int i = 0; i < this->size; i++) {
        mask[i] = false;
    }
}

template<class T, typename Compare>
Heap<T, Compare>::Heap(const Heap& old)
{
    this->size = old.size;
    this->data = new T[this->size];
    this->mask = new bool[this->size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = old.data[i];
        this->mask[i] = old.mask[i];
    }
}

template<class T, typename Compare>
void Heap<T, Compare>::heapifyUp()
{
    int index = size - 1;
    int parent = getParent(index);
    while (index > 0 && Compare(data[index], data[parent])) {
        swap(data[index], data[parent]);
        index = parent;
        parent = getParent(index);
    }
}

template<class T, typename Compare>
void Heap<T, Compare>::heapifyDown()
{
    int index = 0;
    int left = getLeft(index);
    int right = getRight(index);
    while (mask[left] || mask[right]) {
        if (Compare(data[index], data[left])) {
            swap(data[index, data[left]]);
            index = left;
            left = getLeft(index);
            right = getRight(index);
            continue;
        }
        if (Compare(data[index], data[right])) {
            swap(data[index, data[right]]);
            index = right;
            left = getLeft(index);
            right = getRight(index);
            continue;
        }
        break;
    }
}

template<class T, typename Compare>
bool Heap<T, Compare>::insert(const T& insertion)
{
    if (size == capacity) {
        return false;
    }
    mask[size] = true;
    data[size++] = insertion;
    heapifyUp();
}

template<class T, typename Compare>
bool Heap<T, Compare>::extract(T& out)
{
    if (size == 0) {
        return false;
    }
    out = data[0];
    swap(data[0], data[--size]);
    mask[size] = false;
    heapifyDown();
    return true;
}

template<class T, typename Compare>
void Heap<T, Compare>::show() const
{
    cout << "\n| ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " | ";
    }
    cout << '\n';
}

template<class T, typename Compare>
void Heap<T, Compare>::swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}