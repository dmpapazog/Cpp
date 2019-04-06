#include "include/Heap/Heap.h"
#include <iostream>
#include <cstdlib>
#include <functional>

using namespace std;

int main()
{
    Heap<float,    less<float>> minHeap(10);
    Heap<float, greater<float>> maxHeap(10);
    float temp;
    if (minHeap.extract(temp)) {
        cout << temp << '\n';
    } else {
        cout << "The heap is empty.";
    }
    
    minHeap.insert(5.123);      maxHeap.insert(5.123);
    minHeap.insert(5.123);      maxHeap.insert(5.123);
    minHeap.insert(5.123);      maxHeap.insert(5.123);
    minHeap.insert(6.003);      maxHeap.insert(6.003);
    minHeap.insert(15.9);       maxHeap.insert(15.9);
    minHeap.insert(-5.4);       maxHeap.insert(-5.4);
    minHeap.insert(-159.2345);  maxHeap.insert(-159.2345);
    minHeap.insert(12356.01);   maxHeap.insert(12356.01);
    minHeap.insert(978.0009);   maxHeap.insert(978.0009);

    cout << "minHeap:";
    minHeap.show();
    cout << "maxHeap:";
    maxHeap.show();

    if (minHeap.extract(temp)) {
        cout << temp << '\n';
    } else {
        cout << "The heap is empty.";
    }
    minHeap.removeTop();
    minHeap.show();
    minHeap.removeTop();
    minHeap.show();
    minHeap.removeTop();
    minHeap.show();
    minHeap.removeTop();
    minHeap.show();
    minHeap.removeTop();
    minHeap.show();

    maxHeap.removeTop();
    maxHeap.show();
    maxHeap.removeTop();
    maxHeap.show();
    maxHeap.removeTop();
    maxHeap.show();
    maxHeap.removeTop();
    maxHeap.show();
    maxHeap.removeTop();
    maxHeap.show();

    return EXIT_SUCCESS;
}