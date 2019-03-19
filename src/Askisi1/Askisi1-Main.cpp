#include <iostream>
#include "include/Rectangular/Rectangular.h"
#include "include/Square/Square.h"
#include "include/Box/Box.h"

using namespace std;

int main()
{
    // parallilogramma
    Rectangular myRec1(10, 7);
    Rectangular myRec2;
    myRec2.setWidth(10);
    myRec2.setHeight(12);

    cout << "The area of the 1st rectangle is: " << myRec1.getArea() << " [m^2]" << endl;
    cout << "The area of the 2nd rectangle is: " << myRec2.getArea() << " [m^2]" << endl << endl << endl;

    // tetragwna
    Square mySquare1(10);
    Square mySquare2(7);

    cout << "The area of the 1st square is: " << mySquare1.getArea() << " [m^2]\n" 
         << "\t\twith perimeneter: " << mySquare1.getPerimeter() << " [m]" << endl << endl;
    cout << "The area of the 2nd square is: " << mySquare2.getArea() << " [m^2]\n" 
         << "\t\twith perimeneter: " << mySquare2.getPerimeter() << " [m]" << endl << endl;

    // Box
    Box myBox1(10, 10, 10);
    Box myBox2(7, 8, 3);
    cout << "The volume of the 1st box is: " << myBox1.getVolume() << " [m^3]\n" 
         << "\t\twith area: " << myBox1.getArea() << " [m^2]" << endl << endl;
    cout << "The volume of the 2nd box is: " << myBox2.getVolume() << " [m^3]\n" 
         << "\t\twith area: " << myBox2.getArea() << " [m^2]" << endl << endl;

    myBox1.scale(0.5);
    myBox2.scale(2);
    cout << "After scaling the two boxes!! -------------\n";
    cout << "The volume of the 1st box is: " << myBox1.getVolume() << " [m^3]\n" 
         << "\t\twith area: " << myBox1.getArea() << " [m^2]" << endl << endl;
    cout << "The volume of the 2nd box is: " << myBox2.getVolume() << " [m^3]\n" 
         << "\t\twith area: " << myBox2.getArea() << " [m^2]" << endl << endl;


    return 0;
}
