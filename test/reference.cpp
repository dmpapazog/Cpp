#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int &&returnRef()
{
    return 5;
}

int main()
{
    double   a = 5;
    double  &b = a;
    double &&c = 6;
    int      d = c;
    int    &&e = returnRef();

    cout <<   "Size of a: " << sizeof(a);
    cout << "\nSize of b: " << sizeof(b);
    cout << "\nSize of c: " << sizeof(c);
    cout << "\nSize of d: " << sizeof(d);
    cout << "\nSize of e: " << sizeof(e);

    assert(3 > 4);

    return EXIT_SUCCESS;
}