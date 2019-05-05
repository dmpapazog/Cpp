#include "Heap/Heap.h"
#include <iostream>
#include <cstdlib>
#include <functional>
#include <fstream>

using namespace std;

template <class T, class Comp>
void deleteVal(Heap<T, Comp>& heap);

int main(int argc, char const **)
{
    ifstream inputFile;
    inputFile.open("..\\data\\integers.txt");

    if (!inputFile.is_open()) {
        return EXIT_FAILURE;
    }

    long long num, maxLines = 0;
    string line;

    while (getline(inputFile, line)) {
        maxLines++;
    }

    Heap<long long,    less<long long>> minHeap(maxLines);
    Heap<long long, greater<long long>> maxHeap(maxLines);

    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    while (getline(inputFile, line)) {
        num = stoi(line);
        minHeap.insert(num);
        maxHeap.insert(num);
    }
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            deleteVal(minHeap);
            deleteVal(maxHeap);
        }
    }

    if (minHeap.extract(num)) {
        cout << "The minimum is: " << num << '\n';
    } else {
        cout << "Min heap is empty.\n";
    }

    if (maxHeap.extract(num)) {
        cout << "The maximum is: " << num << '\n';
    } else {
        cout << "Max heap is empty.\n";
    }

    cout << "MinHeap: ";
    minHeap.show();
    cout << "\nMaxHeap: ";
    maxHeap.show();

    inputFile.close();
    return EXIT_SUCCESS;
}

template <class T, class Comp>
void deleteVal(Heap<T, Comp>& heap)
{
    if (heap.removeTop()) {
        cout << "Removed top from the heap.\n";
    } else {
        cout << "Heap is empty.\n";
    }
}