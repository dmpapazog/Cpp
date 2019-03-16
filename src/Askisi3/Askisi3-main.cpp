#include <iostream>
#include "include/Set/Set.h"

using namespace std;

int main()
{
    Set mySet1(10);
    mySet1.insert(10);

    Set mySet2(3);
    mySet2.insert(1);
    mySet2.insert(2);
    mySet2.insert(2);

    cout << "mySet1\n";
    mySet1.print();

    cout << "\nmySet2\n";
    mySet2.print();

    mySet1 = mySet2 + 7;

    cout << "\n\nAfter the additions." << endl;
    cout << "mySet1\n";
    mySet1.print();

    cout << "\nmySet2\n";
    mySet2.print();

    return 0;
}