#include <iostream>
#include "include/Array.hpp"

using namespace std;

template<typename T>
void print(Array<T> &myArray);

int main()
{
    int mySize = 100;

    Array<float> myArray(mySize);
    myArray.randomize(3.0, 4.0);

    // print(myArray);
    myArray.quickSort(0, mySize - 1);
    print(myArray);

    cout << "The average is: " << myArray.avg() << endl;

    return 0;
}

template<typename T>
void print(Array<T> &myArray) {
    int i = 0;
    T temp;
    while (myArray.get(i, temp)) {
        cout << "Element " << i << " = " << temp << endl;
        i++;
    }
}