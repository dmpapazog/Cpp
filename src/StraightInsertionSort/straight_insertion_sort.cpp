#include <iostream>
#include "Array/Array.hpp"

using namespace std;

template <typename T>
void straightInsertionSort(Array<T>* array);

int main()
{
    Array<float> myArray(20);
    myArray.randomize(0.0, 100.0);

    cout << "Before the sorting --------" << endl;
    myArray.print();

    straightInsertionSort(&myArray);
    cout << "After the sorting ---------" << endl;
    myArray.print();

    
    return 0;
}

template <typename T>
void straightInsertionSort(Array<T>* array)
{
    int i = 1, j;
    T checkingKey, temp;
    while (array->get(i, checkingKey)) {
        array->get(i, checkingKey);
        j = i - 1;
        while (array->get(j, temp) && checkingKey < temp) {
            array->swap(j, j + 1);
            j--;
        }
        i++;
    }
}