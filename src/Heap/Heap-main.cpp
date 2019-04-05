#include "include/Heap/Heap.h"
#include <iostream>
#include <cstdlib>
#include <functional>

using namespace std;

int main()
{
    Heap<int, less<int>>    minHeap(10);
    Heap<int, greater<int>> maxHeap(10);
    int temp;
    if (minHeap.extract(temp)) {
        cout << temp << '\n';
    } else {
        cout << "The heap is empty.";
    }
    
    minHeap.insert(5);      maxHeap.insert(5);
    minHeap.insert(6);      maxHeap.insert(6);
    minHeap.insert(15);     maxHeap.insert(15);
    minHeap.insert(-5);     maxHeap.insert(-5);
    minHeap.insert(-159);   maxHeap.insert(-159);
    minHeap.insert(12356);  maxHeap.insert(12356);
    minHeap.insert(978);    maxHeap.insert(978);

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

    return EXIT_SUCCESS;
}