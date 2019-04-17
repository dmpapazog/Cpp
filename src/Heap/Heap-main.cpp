#include "include/Heap/Heap.h"
#include <iostream>
#include <cstdlib>
#include <functional>
#include <fstream>

using namespace std;

int main()
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

    inputFile.close();
    return EXIT_SUCCESS;
}