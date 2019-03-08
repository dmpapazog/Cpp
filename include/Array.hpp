#ifndef ARRAY_HPP
#define ARRAY_HPP


template <class T>
class Array {
private:
    T* data;
    int size;
    // Swap the data[i] with data[j]
    int partition(int left, int right, int pivotIndex);

public:
    void swap(int i, int j);
    Array();
    Array(int mySize);
    ~Array();
    bool insert(int pos, T key);
    bool get(int pos, T &key);
    int getSize();
    T Max();
    T Min();
    T sum();
    double avg();
    void randomize(T min, T max);

    // Return the index of key if found. In case
    // of error it return -1
    int search(T key);
    void bubbleSort();
    void bubbleSort2();
    void quickSort(int left, int right);

    void print();
};

#include "Array.cpp"


#endif // ARRAY_HPP