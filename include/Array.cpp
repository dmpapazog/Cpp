#include <random>
#include <ctime>
#include <iostream>
#include "Array.hpp"

using namespace std;

template <class T>
Array<T>::Array()
{
    size = 0;
}

template <class T>
Array<T>::Array(int mySize)
{
    size = mySize;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

template <class T>
Array<T>::~Array()
{
    if (size > 0) {
        delete[] data;
    }
}

template <class T>
int Array<T>::getSize()
{
    return size;
}

template <class T>
T Array<T>::Max()
{
    T temp = data[0];
    for (int i = 1; i < size; i++) {
        if (temp < data[i]) {
            temp = data[i];
        }
    }
    return temp;
}

template <class T>
T Array<T>::Min()
{
    T temp = data[0];
    for (int i = 1; i < size; i++) {
        if (temp > data[i]) {
            temp = data[i];
        }
    }
    return temp;
}

template <class T>
T Array<T>::sum()
{
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

template <class T>
double Array<T>::avg()
{
    return sum() / size;
}

template <>
void Array<int>::randomize(int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
            data[i] = (rand() % (max - min + 1) + min);
        }
}

template <>
void Array<float>::randomize(float min, float max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
            float r = (rand() / (float)RAND_MAX * (max - min)) + min;
            data[i] = r;
        }
}
template <>
void Array<double>::randomize(double min, double max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
            double r = (rand() / (double)RAND_MAX * (max - min)) + min;
            data[i] = r;
        }
}

template <class T>
int Array<T>::search(T key)
{
    int i = 0;
    while (i < size && data[i] != key) {
        i++;
    }
    if (data[i] == key) {
        return i;
    } else {
        return -1;
    }
}

template <class T>
bool Array<T>::insert(int pos, T key)
{
    if (pos < size) {
        data[pos] = key;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Array<T>::get(int pos, T& key)
{
    if (pos < size && pos >= 0) {
        key = data[pos];
        return true;
    } else {
        return false;
    }
}

template <class T>
void Array<T>::swap(int i, int j)
{
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template <class T>
void Array<T>::bubbleSort()
{
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (data[j] < data[j - 1]) {
                swap(j, j - 1);
            }
        }
    }
}

template <class T>
void Array<T>::bubbleSort2()
{
    bool flag = true;
    for (int i = 0; flag && i < size; i++) {
        flag = false;
        for (int j = size - 1; j > i; j--) {
            if (data[j] < data[j - 1]) {
                swap(j, j - 1);
                flag = true;
            }
        }
    }
}

template <class T>
int Array<T>::partition(int left, int right, int pivotIndex)
{
    T pivot = data[pivotIndex];
    swap(right, pivotIndex);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (data[i] < pivot) {
            swap(storeIndex, i);
            storeIndex++;
        }
    }
    swap(storeIndex, right);
    return storeIndex;
}

template <class T>
void Array<T>::quickSort(int left, int right) {
    if (left < right) {
        int pivotIndex = left + (right - left) / 2;
        pivotIndex = partition(left, right, pivotIndex);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }
}

template<typename T>
void Array<T>::print() {
    int i = 0;
    T temp;
    while (get(i, temp)) {
        cout << "Element " << i << " = " << temp << endl;
        i++;
    }
}