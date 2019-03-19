#include <iostream>
#include "include/Circle/Circle.h"
#include "include/Cylinder/Cylinder.h"

using namespace std;

int main()
{
    Circle myCircle(2);
    Cylinder *myCylinder = new Cylinder(10, 2);

    cout << myCircle << endl;
    myCylinder->show();

    delete myCylinder;
    return 0;
}
