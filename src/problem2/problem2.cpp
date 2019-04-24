#include <iostream>
#include <iomanip>
#include <math.h>
#include "Triangle/Triangle.h"

using namespace std;

int main()
{
    Triangle myTriangle(  0.0,   0.0,
                        -11.1, -11.1,
                         50.0,   0.0);

    cout << fixed;
    cout << setprecision(3);

    cout << "Side A_B is: " << setw(6) << myTriangle.sideA_B() << " [m]" << endl;
    cout << "Side B_C is: " << setw(6) << myTriangle.sideB_C() << " [m]" << endl;
    cout << "Side C_A is: " << setw(6) << myTriangle.sideC_A() << " [m]" << endl << endl;

    cout << "Corner A is: " << setw(6) << myTriangle.cornerA() << " [rad]" << endl;
    cout << "Corner B is: " << setw(6) << myTriangle.cornerB() << " [rad]" << endl;
    cout << "Corner C is: " << setw(6) << myTriangle.cornerC() << " [rad]" << endl << endl;

    if (myTriangle.isEquillateral()) {
        cout << left << setw(29) << "The triangle is equillateral." << endl;
    } else {
        cout << left << setw(29) << "The triangle is not equillateral." << endl;
    }
    
    if (myTriangle.isScalene()) {
        cout << left << setw(29) << "The triangle is scalene." << endl;
    } else {
        cout << left << setw(29) << "The triangle is not scalene." << endl;
    }

    if (myTriangle.isRight()) {
        cout << left << setw(29) << "The triangle is right." << endl;
    } else {
        cout << left << setw(29) << "The triangle is not right." << endl;
    }

    if (myTriangle.isAmblygonal()) {
        cout << left << setw(29) << "The triangle is amblygonal." << endl;
    } else {
        cout << left << setw(29) << "The triangle is not amblygonal." << endl;
    }

    if (myTriangle.isAcute_angled()) {
        cout << left << setw(29) << "The triangle is acute-angled." << endl << endl;
    } else {
        cout << left << setw(29) << "The triangle is not acute-angled." << endl << endl;
    }

    cout << left << setw(29) << "The base is side is: " << setw(7) << right << myTriangle.baseSide() << " [m]" << endl;
    cout << left << setw(29) << "The height is: " << setw(7) << right << myTriangle.height() << " [m]" << endl;
    cout << left << setw(29) << "The area of the triangle is: " << setw(7) << right << myTriangle.area() << " [m^2]" << endl << endl;

    return 0;
}
