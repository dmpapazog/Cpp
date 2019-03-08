#include "Cylinder.h"

Cylinder::Cylinder(float height, float radius)
{
    this->height = height;
    this->radius = radius;
}

double Cylinder::getVolume()
{
    return 2 * PI * radius * height;
}

void Cylinder::show() {
    cout << "Radius: " << radius << endl
         << "Height: " << height << endl
         << "Volume: " << getVolume() << endl;
}