#include <iostream>
#include "triangle.hpp"

using namespace std;

int main() {
    Point *A = new Point{1.1, 2.2};
    Point *B = new Point{3.3, 4.4};
    Point *C = new Point{5.5, 6.6};

    Triangle myTriangle(*A, *B, *C);

    for (int i = 0; i < 3; i++) {
        cout << myTriangle.getPoint(i).x << endl;
        cout << myTriangle.getPoint(i).y << endl;
    }

    delete A;
    delete B;
    delete C;

    for (int i = 0; i < 3; i++) {
        cout << myTriangle.getPoint(i).x << endl;
        cout << myTriangle.getPoint(i).y << endl;
    }

    return 0;
}
