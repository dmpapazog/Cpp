#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

using namespace std;

#define PI 3.14159265

class Circle {
    private:
        float radius;
    public:
        Circle() {radius = 0;}
        Circle(float r) { radius = r;}
        float getPerimeter() { return 2*PI*radius;}
        float getArea() {return PI*radius*radius;}
        friend ostream &operator << (ostream &os, Circle &c) {
            os << "Radius: " << c.radius << endl
               << "Perimeter: " << c.getPerimeter() << endl
               << "Area: " << c.getArea() << endl;
            return os;
        }
};


#endif // CIRCLE_H