#include <iostream>
#include "../../include/Polygon/Polygon-template.h"

using namespace std;

int main() {
    Polygon myP(5, 2.456, 6.654, 26.4, 123.5, 789.277893);

    cout << "The length of the polygon is: " << myP.getLength() << endl;

    return 0;
}