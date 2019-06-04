#include <iostream>
#include <cstdlib>

using namespace std;

using IntPtr = int*;

int main()
{
    int a = 5;
    int b = 10;

    IntPtr const myPtr1 = &a;
    const IntPtr const myPtr2 = &b;
    *myPtr1 = 4;
    *myPtr2 = 9;

    cout << *myPtr1 << '\n' 
         << *myPtr2 << '\n';

    return EXIT_SUCCESS;
}